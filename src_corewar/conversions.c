/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:46:11 by fprovolo          #+#    #+#             */
/*   Updated: 2020/12/17 20:15:31 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int     ft_to_int(uint32_t src)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 4)
	{
		res += (src >> ((3 - i) * 8) & 0xff) << i * 8; 
		i++;
	}
	return (res);
}

int		ft_read32(int fd)
{
	uint32_t	buff;
	
	if (read(fd, &buff, 4) != 4)
		terminate("file read error");
	return (ft_to_int(buff));
}