/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:27:58 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/13 14:10:54 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				flag_f(char *res, t_flags flags, int sign)
{
	int			len;
	int			len_fill;
	int			i_width;

	len = ft_strlen(res);
	len_fill = 0;
	if (!(flags.min_width))
		i_width = 0;
	else
		i_width = flags.min_width;
	if (sign == 1 || flags.first_space == 1 || flags.sign == 1)
		len++;
	if (flags.alt_out == 1 && ft_strchr(res, '.') == NULL)
		len++;
	if (flags.zero_padding == 1 && flags.left == 0)
		filler_f(res, width(i_width - len, '0'), flags, sign);
	else
		filler_f(res, width(i_width - len, ' '), flags, sign);
	if (len_fill <= i_width - len)
		len_fill = i_width - len;
	return (len + len_fill);
}

int				flag_e_helper1(int i_width, int len, int *add)
{
	if (0 < i_width - len)
		len = len + (i_width - len);
	free(add);
	return (len);
}

int				flag_e(char *res, int ex, t_flags flags, int sign)
{
	int			len;
	int			i_width;
	int			*add;

	add = (int *)malloc(2);
	add[0] = ex;
	add[1] = sign;
	len = ft_strlen(res);
	if (!(flags.min_width))
		i_width = 0;
	else
		i_width = flags.min_width;
	if (sign == 1 || flags.first_space == 1 || flags.sign == 1)
		len++;
	if (flags.alt_out == 1 && ft_strchr(res, '.') == NULL)
		len++;
	if (add[0] > 99 || add[0] < -99)
		len = len + 5;
	else
		len = len + 4;
	if (flags.zero_padding == 1)
		filler(res, width(i_width - len, '0'), flags, add);
	else
		filler(res, width(i_width - len, ' '), flags, add);
	return (flag_e_helper1(i_width, len, add));
}

char			*width(int len, char c)
{
	char		*res;
	int			i;

	if (len <= 0)
		return (NULL);
	res = ft_strnew(len + 1);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	return (res);
}

void			filler_f(char *res, char *fill, t_flags flags, int sign)
{
	if (flags.zero_padding == 0 && fill != NULL && flags.left == 0)
		ft_putstr(fill);
	if (sign == 1)
		ft_putchar('-');
	else if (flags.sign == 1)
		ft_putchar('+');
	else if (flags.first_space == 1)
		ft_putchar(' ');
	if (flags.zero_padding == 1 && fill != NULL && flags.left == 0)
		ft_putstr(fill);
	ft_putstr(res);
	if (flags.alt_out == 1 && ft_strchr(res, '.') == NULL)
		ft_putchar('.');
	if (fill != NULL && flags.left == 1)
		ft_putstr(fill);
	if (fill != NULL)
		free(fill);
}
