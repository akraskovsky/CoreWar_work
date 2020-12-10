/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:54:44 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 19:01:08 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_double_bin(union u_a_double u_double)
{
	char	*all;
	int		count;
	int		shift;
	int		block;

	all = ft_strnew(81);
	count = 0;
	shift = 7;
	block = 9;
	while (count < 80)
	{
		all[count++] = (char)((u_double.c[block] >> shift--) & 1) + '0';
		if (shift == -1)
		{
			shift = 7;
			block--;
		}
	}
	return (all);
}

char	*ft_mantisa(char *all)
{
	int		i;
	char	*str_man;

	str_man = ft_strnew(65);
	i = 0;
	while (i < 64)
	{
		str_man[i] = all[i + 17];
		i++;
	}
	free(all);
	str_man = mant_bin_to_ten(str_man);
	str_man[0] = '1';
	return (str_man);
}

char	*ft_mant_exp(int exponent, char *str_man)
{
	char	*mant;
	int		count;

	mant = ft_strnew(5002);
	count = 0;
	while (count <= 5000)
		mant[count++] = '0';
	if (exponent > 0)
		mant = mult2_mant_exppositive(mant, str_man, exponent);
	else if (exponent < 0)
		mant = mult2_mant_expnegative(mant, str_man, exponent);
	else if (exponent == 0)
	{
		free(mant);
		mant = str_man;
		mant[1] = '.';
	}
	if (mant != str_man)
		free(str_man);
	return (mant);
}

int		ft_exponent(char *all)
{
	char	*str_exp;
	int		i;
	int		exponent;

	str_exp = ft_strnew(16);
	i = 0;
	while (i < 15)
	{
		str_exp[i] = all[i + 1];
		i++;
	}
	exponent = ft_atoi_base(str_exp, 2);
	free(str_exp);
	exponent -= 16383;
	return (exponent);
}

int		find_e(char *str, double num)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (num == 0.0 || num == -0.0)
		return (0);
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (i > 1 && str[1] != '0' && ft_strchr(str, '.') != NULL)
		return (i - 2);
	else if (i == (int)ft_strlen(str))
		return (find_e_helper(i, j, str));
	else
	{
		i++;
		j = -1;
		while (str[i] == '0' && str[i] != '\0')
		{
			j--;
			i++;
		}
		return (j);
	}
}
