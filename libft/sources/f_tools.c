/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:38:29 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/07 15:11:22 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*calc_add(char *two, char *res)
{
	int i;
	int temp;

	i = ft_strlen(two) - 1;
	temp = 0;
	while (i > 1)
	{
		res[i] = ((two[i] - '0') + (res[i] - '0')) + '0';
		if (temp == 1)
		{
			res[i] += 1;
			temp = 0;
		}
		if (res[i] > '9')
		{
			res[i] -= 10;
			temp = 1;
		}
		i--;
	}
	res[1] = '.';
	res[0] = '0';
	free(two);
	return (res);
}

void	negative2power(char *res, int power)
{
	int i;
	int old_temp;
	int new_temp;

	i = 5000;
	old_temp = 0;
	while (power >= 1)
	{
		while (i >= 0)
		{
			new_temp = ((res[i] - '0') * 5) / 10;
			res[i] = (((res[i] - '0') * 5) % 10) + '0' + old_temp;
			i--;
			old_temp = new_temp;
		}
		i = 5000;
		power--;
		old_temp = 0;
	}
}

char	*calc_negative2power(int power)
{
	char	*res;
	int		i;

	res = ft_strnew(5002);
	res[5000] = '1';
	i = 0;
	while (i < 5000)
	{
		res[i] = '0';
		i++;
	}
	power = power * -1;
	negative2power(res, power);
	return (put_dot(res, -power));
}

char	*mant_bin_to_ten(char *str_mant)
{
	char	*ten;
	int		i;
	int		j;

	ten = ft_strnew(5002);
	i = 0;
	while (i <= 5000)
		ten[i++] = '0';
	j = 0;
	i = 0;
	while (str_mant[j] != '\0')
	{
		i--;
		if (str_mant[j] == '1')
			ten = calc_add(calc_negative2power(i), ten);
		j++;
	}
	free(str_mant);
	return (ten);
}

char	*calc_mult2(char *res)
{
	int	len;
	int	temp;

	len = ft_strlen(res) - 1;
	temp = 0;
	while (len >= 0)
	{
		if (res[len] == '.')
			len--;
		else
		{
			res[len] = ((res[len] - '0') * 2) + '0';
			if (temp == 1)
			{
				res[len] += 1;
				temp = 0;
			}
			if (res[len] > '9')
			{
				res[len] -= 10;
				temp = 1;
			}
			len--;
		}
	}
	return (res);
}
