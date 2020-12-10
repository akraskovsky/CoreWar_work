/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:49:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/28 15:05:58 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_fd(int fd, const char *str, ...)
{
	va_list	ap;
	t_flags	flags;
	int		length;
	int		i;

	length = 0;
	flags.fd = fd;
	va_start(ap, str);
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != '%' && str[i] != '{' && str[i] != '\0')
			i++;
		write(flags.fd, str, i);
		length += i;
		str += i;
		if (*str == '\0')
			return (length);
		if (!(parse_format((char **)&str, &flags, ap)))
			return (-1);
		length += flags.field_len;
	}
	va_end(ap);
	return (length);
}
