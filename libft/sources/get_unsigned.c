/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/05 13:05:11 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_arg_len_u(t_flags *flags, uintmax_t num, int base)
{
	size_t		len;
	uintmax_t	calc_num;

	len = 1;
	calc_num = num;
	if (num == 0 && flags->precision == 0 && flags->precision_set)
		len = 0;
	while (calc_num /= base)
		len++;
	if (flags->alt_out && flags->conversion == 'o' && !(len == 1 && num == 0))
		len++;
	if (flags->precision > len)
		len = flags->precision;
	if (flags->conversion == 'p' || ((flags->alt_out) && (num > 0) &&
			(flags->conversion == 'x' || flags->conversion == 'X')))
		len += 2;
	if (flags->min_width > len && flags->zero_padding &&
			!flags->left && !flags->precision_set)
		len = flags->min_width;
	return (len);
}

static int		pf_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'u')
		return (10);
	return (16);
}

static char		to_char(char c, char conversion)
{
	if (c <= 9)
		return (c + 48);
	if (conversion == 'X')
		return (c + 55);
	return (c + 87);
}

static int		unsigned_to_str(t_flags *flags, uintmax_t num)
{
	size_t		arg_len;
	size_t		shift;
	int			base;
	uintmax_t	num_bkp;

	num_bkp = num;
	base = pf_base(flags->conversion);
	arg_len = get_arg_len_u(flags, num, base);
	flags->field_len = (flags->min_width > arg_len) ?
					flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	if ((flags->arg = ft_strnewfill(flags->field_len, ' ')))
	{
		while (arg_len--)
		{
			flags->arg[arg_len + shift] =
					to_char((char)(num % base), flags->conversion);
			num /= base;
		}
		if (flags->conversion == 'p' ||
				(flags->alt_out && base == 16 && num_bkp != 0))
			flags->arg[shift + 1] = (flags->conversion == 'X') ? 'X' : 'x';
	}
	return ((flags->arg) ? 1 : 0);
}

int				get_unsigned(t_flags *flags, va_list ap)
{
	uintmax_t	num;

	num = 0;
	if (flags->conversion == 'p')
		num = (unsigned long long)va_arg(ap, void *);
	else if (flags->mod_char)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (flags->mod_short)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->mod_long)
		num = va_arg(ap, unsigned long);
	else if (flags->mod_long_long)
		num = va_arg(ap, unsigned long long);
	else if (flags->mod_max)
		num = va_arg(ap, uintmax_t);
	else if (flags->mod_size_t)
		num = (uintmax_t)va_arg(ap, size_t);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	return (unsigned_to_str(flags, num));
}
