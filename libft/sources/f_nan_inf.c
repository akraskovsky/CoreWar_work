/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_nan_inf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:54:59 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 18:58:44 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_nan_inf(double i, t_flags flags)
{
	char	*res;
	int		count;

	if (i != i)
		res = ft_strdup("nan");
	else
		res = ft_strdup("inf");
	count = 0;
	if (flags.conversion == 'F' || flags.conversion == 'E' \
		|| flags.conversion == 'G')
	{
		while (res[count] != '\0')
		{
			res[count] = ft_toupper(res[count]);
			count++;
		}
	}
	return (res);
}

int		filler_nan_helper(char *res, char *fill, t_flags d)
{
	int	len_fill;

	ft_putstr(res);
	if (fill != NULL && d.left == 1)
		ft_putstr(fill);
	if (fill != NULL)
	{
		len_fill = ft_strlen(fill);
		free(fill);
		return (len_fill);
	}
	return (0);
}

int		ft_nan(char *r, t_flags d, int sign, char *all)
{
	int		len;
	char	*fill;
	int		len_fill;

	len = 3;
	len_fill = 0;
	free(all);
	if ((sign == 1 || d.first_space == 1 || d.sign == 1)
		&& r[0] != 'n' && r[0] != 'N')
		len++;
	fill = width(d.min_width - len, ' ');
	if (fill != NULL && d.left == 0)
		ft_putstr(fill);
	if (sign == 1 && (r[0] != 'n' && r[0] != 'N'))
		ft_putchar('-');
	else if (d.sign == 1 && (r[0] != 'n' && r[0] != 'N'))
		ft_putchar('+');
	else if (d.first_space == 1 && (r[0] != 'n' && r[0] != 'N'))
		ft_putchar(' ');
	len_fill = filler_nan_helper(r, fill, d);
	return (len + len_fill);
}
