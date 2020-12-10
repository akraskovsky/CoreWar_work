/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_normalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:23:42 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 15:05:49 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_norm(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] != '.')
		i--;
	while (i >= 1)
	{
		str[i] = str[i - 1];
		i--;
	}
	str[1] = '.';
}

int		normalize_helper1(char *str)
{
	int	i;

	i = 3;
	while (str[i] == '0')
		i++;
	return (i);
}

void	normalize_helper2(char *str)
{
	int	j;

	j = ft_strlen(str) - 1;
	while (str[j] != '.')
		j--;
	while (j >= 2)
	{
		str[j] = str[j - 1];
		j--;
	}
}

char	*normalize(char *str)
{
	char	*res;
	int		i;

	if (str[2] == '.' && str[1] != '0')
		return (str);
	else if (str[2] == '.' && str[1] == '0')
	{
		str[2] = '0';
		i = normalize_helper1(str);
		str[i - 1] = str[i];
		str[i] = '.';
		res = cut_zeros_before(str);
	}
	else
	{
		i = ft_strlen(str) - 1;
		while (str[i] != '.' && i > 0)
			i--;
		if (i == 0)
			i = 2;
		normalize_helper2(str);
		str[2] = '.';
		res = str;
	}
	return (res);
}

int		ft_get_exp_for_e(double i)
{
	int					ex;
	union u_a_double	u_double;
	char				*all;
	char				*res;

	u_double.a = i;
	all = get_double_bin(u_double);
	{
		ex = ft_exponent(all);
		if (i != 2.0 && i != -2.0)
		{
			res = ft_mant_exp(ex, ft_mantisa(all));
			res = cut_zeros_before(res);
		}
		else
			res = ft_strdup("02.0");
	}
	ex = find_e(res, i);
	free(res);
	return (ex);
}
