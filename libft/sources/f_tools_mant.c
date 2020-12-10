/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tools_mant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:46:44 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 19:17:34 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calc_div_helper(char *mant, int i)
{
	while (i - 1 >= 0 && mant[i] != '.')
	{
		mant[i + 1] = mant[i];
		if (i - 1 >= 0 && mant[i - 1] == '.')
			mant[i] = '0';
		i--;
	}
}

void	calc_div_helper2(int i, char *mant, int old_temp)
{
	mant[i] = ((mant[i] - '0' + 10) / 2) + '0' + old_temp;
	mant[1] = '0';
}

char	*calc_div_by_half(char *mant)
{
	int i;
	int old_temp;
	int new_temp;

	i = 5000;
	while (mant[i] == '0')
		i--;
	calc_div_helper(mant, i);
	i = 5000;
	old_temp = 0;
	while (i > 2)
	{
		if (mant[1] == '0' || mant[i - 1] != '.')
		{
			new_temp = ((mant[i] - '0') * 5) / 10;
			mant[i] = (((mant[i] - '0') * 5) % 10) + '0' + old_temp;
			old_temp = new_temp;
		}
		else if (mant[1] != '0' && mant[i - 1] == '.')
			calc_div_helper2(i, mant, old_temp);
		i--;
	}
	return (mant);
}

char	*mult2_mant_expnegative(char *res, char *mant, int exponent)
{
	int	i;

	i = 0;
	while (i <= 64)
	{
		res[i + 1] = mant[i];
		i++;
	}
	if (res[2] != '.')
		res[2] = '.';
	while (exponent < 0)
	{
		res = calc_div_by_half(res);
		exponent++;
	}
	return (res);
}

char	*mult2_mant_exppositive(char *res, char *mant, int exponent)
{
	int	i;
	int	j;

	i = 5000;
	j = 64;
	while (j >= 0)
	{
		res[i] = mant[j];
		i--;
		j--;
	}
	while (exponent > 0)
	{
		calc_mult2(res);
		exponent--;
	}
	return (res);
}
