/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:22:49 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/17 22:03:42 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digits(int n)
{
	int	nd;

	nd = 1;
	while (n /= 10)
		nd++;
	return (nd);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		count;

	sign = (n < 0) ? 1 : 0;
	count = ft_digits(n);
	if ((str = ft_strnew(count + sign)))
	{
		if (sign)
			*str = '-';
		while (count--)
		{
			if (sign)
				str[count + sign] = (n % 10 * -1) + '0';
			else
				str[count] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}
