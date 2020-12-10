/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/07 15:46:05 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clear_modificators(t_flags *flags)
{
	flags->mod_char = 0;
	flags->mod_short = 0;
	flags->mod_long = 0;
	flags->mod_long_long = 0;
	flags->mod_long_double = 0;
	flags->mod_max = 0;
	flags->mod_size_t = 0;
	return ;
}

static void	arg_to_low(t_flags *flags)
{
	if (flags->conversion == 'D' || flags->conversion == 'O'\
			|| flags->conversion == 'U')
	{
		flags->conversion += 32;
		clear_modificators(flags);
		flags->mod_long = 1;
	}
}

int			get_argument(t_flags *flags, va_list ap)
{
	int			ret;

	arg_to_low(flags);
	ret = 1;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		ret = get_int(flags, ap);
	if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		ret = get_unsigned(flags, ap);
	if (flags->conversion == 's')
		ret = get_string(flags, ap);
	if (flags->conversion == 'c' || flags->conversion == '%')
		ret = get_character(flags, ap);
	if (flags->conversion == 'f' || flags->conversion == 'F' ||\
			flags->conversion == 'g' || flags->conversion == 'G' ||\
			flags->conversion == 'e' || flags->conversion == 'E')
		get_f_double(flags, ap);
	if (ret && flags->arg != NULL)
	{
		write(flags->fd, flags->arg, flags->field_len);
		free(flags->arg);
	}
	return (ret);
}
