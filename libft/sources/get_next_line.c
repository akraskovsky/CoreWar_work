/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:53:41 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/20 15:26:01 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_get_buff(int fd, t_lst **buffers)
{
	t_lst	*current;

	current = *buffers;
	while (current != NULL && current->fd != fd)
		current = current->next;
	if (current == NULL)
	{
		if (!(current = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		if (!(current->buff = ft_strnew(BUFF_SIZE)))
		{
			free(current);
			return (NULL);
		}
		current->fd = fd;
		current->next = *buffers;
		*buffers = current;
	}
	return (current->buff);
}

void	gnl_free_buff(int fd, t_lst **buffers)
{
	t_lst	*ptr;
	t_lst	*del;

	ptr = *buffers;
	if ((*buffers)->fd == fd)
	{
		*buffers = (*buffers)->next;
		free(ptr->buff);
		free(ptr);
		return ;
	}
	while (ptr->next != NULL)
	{
		if (ptr->next->fd == fd)
		{
			del = ptr->next;
			ptr->next = ptr->next->next;
			free(del->buff);
			free(del);
			return ;
		}
		ptr = ptr->next;
	}
	return ;
}

int		add_to_line(char **line, char *buff, size_t size)
{
	char	*tmp;
	char	*string;

	if (!(string = ft_strnew(ft_strlen(*line) + size)))
		return (0);
	ft_strcpy(string, *line);
	ft_strncpy(string + ft_strlen(*line), buff, size);
	tmp = *line;
	*line = string;
	free(tmp);
	if (size < ft_strlen(buff))
		ft_strcpy(buff, buff + size + 1);
	else
		ft_bzero(buff, BUFF_SIZE + 1);
	return (1);
}

int		read_to_buff(int fd, char **line, char *buff, t_lst **buffers)
{
	int	len;

	add_to_line(line, buff, ft_strlen(buff));
	ft_bzero(buff, BUFF_SIZE + 1);
	if ((len = read(fd, buff, BUFF_SIZE)) <= 0)
		gnl_free_buff(fd, buffers);
	return (len);
}

int		get_next_line(const int fd, char **line)
{
	size_t			i;
	int				len;
	char			*buff;
	static t_lst	*buffers;

	if ((!line) || !(*line = ft_strnew(0)))
		return (-1);
	if ((buff = gnl_get_buff(fd, &buffers)))
	{
		i = 0;
		while (buff[i++] != '\n')
			if (buff[i - 1] == '\0')
			{
				if ((len = read_to_buff(fd, line, buff, &buffers)) <= 0)
					return ((**line == '\0') ? len : 1);
				i = 0;
			}
		if (add_to_line(line, buff, i - 1))
			return (1);
	}
	return (-1);
}
