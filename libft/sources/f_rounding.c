/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rounding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:25:15 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/03 19:14:49 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cut_zero_before(char *mant)
{
	char	*newstr;
	int		k;
	int		i;

	if (mant[0] == '0')
	{
		newstr = ft_strnew(ft_strlen(mant));
		k = 1;
		i = 0;
		while (mant[k] != '\0')
		{
			newstr[i] = mant[k];
			i++;
			k++;
		}
		free(mant);
		mant = newstr;
	}
	return (mant);
}

void	more_rounding(char *mant, int i)
{
	int temp;

	temp = 0;
	while (i >= 0)
	{
		(mant[i] == '.') ? i-- : i;
		if (temp == 1)
		{
			mant[i] += 1;
			temp = 0;
		}
		if (mant[i] > '9')
		{
			mant[i] -= 10;
			temp = 1;
		}
		i--;
	}
}

void	tryrounding(char *mant, int p)
{
	int i;
	int len;
	int temp;

	i = 1;
	temp = 0;
	while (mant[i - 1] != '.')
		i++;
	i = i + p;
	len = ft_strlen(mant) - 1;
	if (mant[i] == '5')
	{
		while (len > i)
		{
			if (mant[len] > '0' && mant[len] <= '9')
				temp = 1;
			len--;
		}
	}
	if (temp == 1)
		mant[i] += 1;
}

void	rounding_all(char *mant, int precision)
{
	int i;
	int j;

	i = 1;
	while ((mant[i - 1] != '.') && (mant[i] != '\0'))
		i++;
	i += precision;
	tryrounding(mant, precision);
	rounding_dot_5(mant, i);
	more_rounding(mant, i - 1);
	j = ft_strlen(mant);
	while (i < j)
	{
		mant[i] = 'z';
		i++;
	}
}

char	*ft_bank_rounding(char *mant, size_t precision, int pre_set)
{
	int		i;
	size_t	j;
	int		k;

	i = 2;
	j = 0;
	(!(pre_set)) ? precision = 6 : precision;
	while ((mant[i - 1] != '.') && (mant[i] != '\0'))
		i++;
	k = i;
	while (mant[i++] != '\0')
		j++;
	if (precision >= j)
	{
		j = precision - j;
		mant = ft_straddzero(mant, j);
	}
	else
	{
		rounding_all(mant, precision);
		(precision == 0) ? mant[k - 1] = 'z' : k;
		mant = cut_z_after(mant);
	}
	mant = cut_zero_before(mant);
	return (mant);
}
