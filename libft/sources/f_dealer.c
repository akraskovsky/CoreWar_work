/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dealer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:11:50 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 18:47:33 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_dot(char *res, int power)
{
	int i;
	int j;

	i = 0;
	j = 1;
	res[5000 + power] = '.';
	while (res[i] != '.')
		i++;
	while (res[i] != '\0')
	{
		res[j] = res[i];
		j++;
		i++;
	}
	while (res[j] != '\0')
	{
		res[j] = '0';
		j++;
	}
	return (res);
}

void	without_dot(long double num, char *res)
{
	int		i;
	char	*temp;

	i = (int)num;
	temp = ft_itoa(i);
	i = ft_strlen(temp);
	res[i] = '.';
	free(temp);
}

char	*f_dealer(int exponent, char *all, char *res, long double i)
{
	res = ft_mant_exp(exponent, ft_mantisa(all));
	res = cut_zeros_before(res);
	if (ft_strchr(res, '.') == NULL)
		without_dot(i, res);
	return (res);
}

int		find_e_helper(int i, int j, char *str)
{
	i--;
	while (str[i] == '0')
		i--;
	while (i >= 0)
	{
		i--;
		j++;
	}
	if (str[0] == '0')
		j = j - 2;
	return (j);
}

void	filler(char *res, char *fill, t_flags flags, int *add)
{
	if (flags.zero_padding == 0 && fill != NULL && flags.left == 0)
		ft_putstr(fill);
	if (add[1] == 1)
		ft_putchar('-');
	else if (flags.sign == 1)
		ft_putchar('+');
	else if (flags.first_space == 1)
		ft_putchar(' ');
	if (flags.zero_padding == 1 && fill != NULL)
		ft_putstr(fill);
	ft_putstr(res);
	if (flags.alt_out == 1 && ft_strchr(res, '.') == NULL)
		ft_putchar('.');
	(flags.conversion == 'E' || flags.conversion == 'G') \
		? ft_putchar('E') : ft_putchar('e');
	(add[0] >= 0) ? ft_putstr("+") : ft_putstr("-");
	if (add[0] <= 9 && add[0] >= -9)
		ft_putchar('0');
	ft_putnbr_e(-add[0]);
	if (fill != NULL && flags.left == 1)
		ft_putstr(fill);
	if (fill != NULL)
		free(fill);
}
