/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:51:11 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/28 15:35:12 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_ph_colors(char **ptr, t_flags *flags)
{
	int		len;

	if (!ft_strncmp(*ptr, "{BLK}", 5))
		len = write(flags->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(*ptr, "{RED}", 5))
		len = write(flags->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(*ptr, "{GRN}", 5))
		len = write(flags->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(*ptr, "{YEL}", 5))
		len = write(flags->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(*ptr, "{BLU}", 5))
		len = write(flags->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(*ptr, "{MGT}", 5))
		len = write(flags->fd, "\x1B[35m", 5);
	else if (!ft_strncmp(*ptr, "{CYN}", 5))
		len = write(flags->fd, "\x1B[36m", 5);
	else if (!ft_strncmp(*ptr, "{WHT}", 5))
		len = write(flags->fd, "\x1B[37m", 5);
	else
		return (1);
	*ptr += 5;
	return (len);
}

static int	set_bg_colors(char **ptr, t_flags *flags)
{
	int		len;

	if (!ft_strncmp(*ptr, "{BGC:BLK}", 9))
		len = write(flags->fd, "\x1B[40m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:RED}", 9))
		len = write(flags->fd, "\x1B[41m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:GRN}", 9))
		len = write(flags->fd, "\x1B[42m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:YEL}", 9))
		len = write(flags->fd, "\x1B[43m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:BLU}", 9))
		len = write(flags->fd, "\x1B[44m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:MGT}", 9))
		len = write(flags->fd, "\x1B[45m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:CYN}", 9))
		len = write(flags->fd, "\x1B[46m", 5);
	else if (!ft_strncmp(*ptr, "{BGC:WHT}", 9))
		len = write(flags->fd, "\x1B[47m", 5);
	else
		return (1);
	*ptr += 9;
	return (len);
}

int			ft_set_colors(char **ptr, t_flags *flags)
{
	int		len;

	if (!ft_strncmp(*ptr, "{OFF}", 5))
	{
		len = write(flags->fd, "\x1B[40m\x1B[37m", 10);
		*ptr += 5;
	}
	else if (!ft_strncmp(*ptr, "{BGC:", 5))
		len = set_bg_colors(ptr, flags);
	else
		len = set_ph_colors(ptr, flags);
	if (len == 1)
	{
		write(flags->fd, "{", 1);
		*ptr += 1;
	}
	return (len);
}
