/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:58:51 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/19 13:59:50 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int		ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f' || \
			c == ' ');
}
*/

static int		ft_base(char c, int base)
{
	char				*str;
	char				*str1;
	int					i;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	i = 0;
	while ((str[i] || str1[i]) && i < base)
	{
		if (c == str[i] || c == str1[i])
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int					neg;
	int					res;

	res = 0;
	neg = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && ft_base(*str, str_base) != -1)
	{
		res = (res * str_base) + ft_base(*str, str_base);
		str++;
	}
	return (res * neg);
}

char			*ft_e_helper2(double i, char *res, t_flags *flags)
{
	res = ft_bank_rounding(res, flags->precision, flags->precision_set);
	if (i != -0.0 || i != 0.0)
		res = cut_zero_before(res);
	if (res[0] == '1')
		round_norm(res);
	return (res);
}

void			rounding_dot_5(char *mant, int i)
{
	if (mant[i] > '5')
	{
		if (mant[i - 1] != '.')
			mant[i - 1] += 1;
		else
			mant[i - 2] += 1;
	}
	else if (mant[i] == '5' && mant[i - 1] != '.')
	{
		if ((mant[i - 1] - '0') % 2 == 1)
			mant[i - 1] += 1;
	}
	else if (mant[i] == '5' && mant[i - 1] == '.')
	{
		if (((mant[i - 2] - '0') % 2 == 1))
			mant[i - 2] += 1;
	}
}
