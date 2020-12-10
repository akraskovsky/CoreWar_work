/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_long_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:19:07 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 19:16:37 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_ef_double(t_flags *flags, va_list ap)
{
	double				num;
	long double			i;

	i = 0;
	num = 0;
	if ((flags->conversion == 'e' || flags->conversion == 'E') && \
		!(flags->mod_long_double))
	{
		num = va_arg(ap, double);
		flags->field_len = (ft_printf_e_double(num, *flags));
	}
	else if ((flags->conversion == 'e' || flags->conversion == 'E') \
		&& flags->mod_long_double)
	{
		i = va_arg(ap, long double);
		flags->field_len = (ft_printf_le_double(i, *flags));
	}
}

char			*ft_le_helper1(long double i, char *res, char *all)
{
	int					ex;

	if (i == 0.0 || i == -0.0)
	{
		res = ft_strdup("00.0");
		ex = 0;
	}
	else
	{
		ex = ft_exponent(all);
		if (i != 2.0 && i != -2.0)
			res = f_dealer(ex, all, res, i);
		else
			res = ft_strdup("02.0");
	}
	return (res);
}

int				ft_printf_le_double(long double i, t_flags flags)
{
	char				*all;
	char				*res;
	int					ex;
	int					sign;

	all = ft_e_helper(&sign, i);
	res = NULL;
	if (i != i || i == +1.0L / 0.0L || i == -1.0L / 0.0L)
	{
		res = ft_nan_inf(i, flags);
		ex = ft_nan(res, flags, sign, all);
	}
	else
	{
		res = ft_le_helper1(i, res, all);
		ex = find_e(res, i);
		if (i != -0.0L || i != 0.0L)
			res = normalize(res);
		res = ft_e_helper2(i, res, &flags);
		if (flags.conversion == 'G' || flags.conversion == 'g')
			res = ft_cut_zero(res);
		ex = flag_e(res, ex, flags, sign);
	}
	free(res);
	return (ex);
}

int				ft_printf_e_double(double i, t_flags flags)
{
	char				*all;
	char				*res;
	int					ex;
	int					sign;

	all = ft_e_helper(&sign, i);
	res = NULL;
	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
	{
		res = ft_nan_inf(i, flags);
		ex = ft_nan(res, flags, sign, all);
	}
	else
	{
		res = ft_e_helper1(i, res, all);
		ex = find_e(res, i);
		if (i != -0.0 || i != 0.0)
			res = normalize(res);
		res = ft_e_helper2(i, res, &flags);
		if (flags.conversion == 'G' || flags.conversion == 'g')
			res = ft_cut_zero(res);
		ex = flag_e(res, ex, flags, sign);
	}
	free(res);
	return (ex);
}

int				ft_get_exp_for_le(long double i)
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
