/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_long_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:09:39 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/29 19:10:55 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_gf_double(t_flags *flags, va_list ap)
{
	double				num;
	long double			i;

	i = 0;
	num = 0;
	if ((flags->conversion == 'g' || flags->conversion == 'G') && \
		!(flags->mod_long_double))
	{
		num = va_arg(ap, double);
		flags->field_len = (ft_printf_g_double(num, flags));
	}
	else if ((flags->conversion == 'g' || flags->conversion == 'G') \
		&& flags->mod_long_double)
	{
		i = va_arg(ap, long double);
		flags->field_len = (ft_printf_lg_double(i, flags));
	}
}

int				ft_printf_g_double(double i, t_flags *flags)
{
	int					ex;

	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
		ex = ft_printf_f_double(i, flags);
	else
	{
		if (flags->precision == 0 && !(flags->precision_set))
			flags->precision = 6;
		else if (flags->precision == 0)
			flags->precision = 1;
		ex = ft_get_exp_for_e(i);
		if (ex < -4 || ex >= (int)(flags->precision))
		{
			flags->precision -= 1;
			ex = ft_printf_e_double(i, *flags);
		}
		else
		{
			flags->precision = flags->precision - 1 - ex;
			ex = ft_printf_f_double(i, flags);
		}
	}
	return (ex);
}

int				ft_printf_lg_double(long double i, t_flags *flags)
{
	int					ex;

	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
		ex = ft_printf_l_double(i, flags);
	else
	{
		if (flags->precision == 0 && !(flags->precision_set))
			flags->precision = 6;
		else if (flags->precision == 0)
			flags->precision = 1;
		ex = ft_get_exp_for_le(i);
		if (ex < -4 || ex >= (int)(flags->precision))
		{
			flags->precision -= 1;
			ex = ft_printf_le_double(i, *flags);
		}
		else
		{
			flags->precision = flags->precision - 1 - ex;
			ex = ft_printf_l_double(i, flags);
		}
	}
	return (ex);
}

char			*ft_e_helper(int *sign, double i)
{
	char				*all;
	union u_a_double	u_double;

	u_double.a = i;
	all = get_double_bin(u_double);
	*sign = all[0] - '0';
	return (all);
}

char			*ft_e_helper1(double i, char *res, char *all)
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
			res = f_dealer(ex, all, res, (long double)i);
		else
			res = ft_strdup("02.0");
	}
	return (res);
}
