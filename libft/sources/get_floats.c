/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:03:53 by jmalik            #+#    #+#             */
/*   Updated: 2020/02/05 16:01:40 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_f_double(t_flags *flags, va_list ap)
{
	double				num;
	long double			i;

	i = 0;
	num = 0;
	if ((flags->conversion == 'f' || flags->conversion == 'F') && \
		!(flags->mod_long_double))
	{
		num = va_arg(ap, double);
		flags->field_len = (ft_printf_f_double(num, flags));
	}
	else if ((flags->conversion == 'f' || flags->conversion == 'F') \
		&& flags->mod_long_double)
	{
		i = va_arg(ap, long double);
		flags->field_len = (ft_printf_l_double(i, flags));
	}
	else if (flags->conversion == 'g' || flags->conversion == 'G')
		get_gf_double(flags, ap);
	else if (flags->conversion == 'e' || flags->conversion == 'E')
		get_ef_double(flags, ap);
}

int			ft_printf_l_double(long double i, t_flags *flags)
{
	char				*all;
	char				*res;
	int					exponent;
	int					sign;

	res = NULL;
	all = ft_char_from_union(&sign, i);
	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
	{
		res = ft_nan_inf(i, *flags);
		exponent = ft_nan(res, *flags, sign, all);
	}
	else
	{
		res = ld_char_ten(i, all, res, flags);
		exponent = flag_f(res, *flags, sign);
	}
	free(res);
	return (exponent);
}

int			ft_printf_f_double(double i, t_flags *flags)
{
	double				k;
	int					length;

	k = (double)i;
	length = ft_printf_l_double(k, flags);
	return (length);
}

char		*ft_char_from_union(int *sign, long double i)
{
	union u_a_double	u_double;
	char				*all;

	u_double.a = i;
	all = get_double_bin(u_double);
	*sign = all[0] - '0';
	return (all);
}

char		*ld_char_ten(long double i, char *all, char *res, t_flags *flags)
{
	int					exponent;

	if (i == 0.0 || i == -0.0)
		res = ft_strdup("00.0");
	else
	{
		exponent = ft_exponent(all);
		if (i != 2.0 && i != -2.0)
			res = f_dealer(exponent, all, res, i);
		else
			res = ft_strdup("02.0");
	}
	res = ft_bank_rounding(res, flags->precision, flags->precision_set);
	if (flags->conversion == 'G' || flags->conversion == 'g' \
		|| ((flags->mod_long_double) && (flags->conversion == 'G' || \
		flags->conversion == 'g')))
		res = ft_cut_zero(res);
	return (res);
}
