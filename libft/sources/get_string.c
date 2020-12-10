/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:13:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/05 13:05:11 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_string(t_flags *flags, va_list ap)
{
	char	*string;
	size_t	arg_len;
	size_t	shift;
	char	fill;

	string = va_arg(ap, char *);
	if (string == NULL)
		arg_len = 6;
	else
		arg_len = ft_strlen(string);
	if (flags->precision_set && flags->precision < arg_len)
		arg_len = flags->precision;
	flags->field_len = (flags->min_width > arg_len) ?
			flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	fill = (flags->zero_padding && !flags->left) ? '0' : ' ';
	if ((flags->arg = ft_strnewfill(flags->field_len, fill)))
	{
		if (string != NULL)
			ft_memcpy(flags->arg + shift, string, arg_len);
		else
			ft_memcpy(flags->arg + shift, "(null)", arg_len);
	}
	return ((flags->arg) ? 1 : 0);
}
