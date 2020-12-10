/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 22:31:27 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/17 23:07:13 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	char			digit;

	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(n * -1);
	}
	else
	{
		nbr = (unsigned int)n;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	digit = (char)(nbr % 10 + '0');
	write(fd, &digit, 1);
}
