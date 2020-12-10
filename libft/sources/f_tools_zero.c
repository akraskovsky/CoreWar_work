/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tools_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:17:04 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/03 18:57:17 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_e(int n)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
		ft_putnbr_e(n / 10);
	ft_putchar((n % 10) + '0');
}

char	*ft_straddzero(char *mant, int zeros)
{
	int		i;
	char	*temp;
	char	*res;

	if (zeros <= 0)
		return (mant);
	temp = ft_strnew(zeros + 1);
	i = 0;
	while (i < zeros)
	{
		temp[i] = '0';
		i++;
	}
	res = ft_strjoin(mant, temp);
	free(mant);
	free(temp);
	return (res);
}

char	*cut_zeros_before(char *mant)
{
	int		i;
	int		j;
	int		k;
	char	*newstr;

	i = 0;
	j = ft_strlen(mant);
	while (mant[i] == '0' && mant[i + 1] != '.')
		i++;
	newstr = ft_strnew(j - i + 2);
	k = 1;
	newstr[0] = '0';
	while (i <= j)
		newstr[k++] = mant[i++];
	free(mant);
	mant = newstr;
	return (mant);
}

char	*cut_z_after(char *mant)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = ft_strlen(mant) - 1;
	while (mant[j - 1] == 'z')
		j--;
	newstr = ft_strnew(j + 1);
	while (i < j)
	{
		newstr[i] = mant[i];
		i++;
	}
	free(mant);
	return (newstr);
}

char	*ft_cut_zero(char *res)
{
	char	*new;
	int		i;

	i = ft_strlen(res) - 1;
	while (res[i] == '0')
		i--;
	if (res[i] == '.')
		i--;
	new = ft_strnew(i + 2);
	while (i >= 0)
	{
		new[i] = res[i];
		i--;
	}
	free(res);
	return (new);
}
