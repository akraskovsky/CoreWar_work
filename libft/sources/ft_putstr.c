/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:53:34 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/17 22:04:59 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	char	*ptr;

	if (!str)
		return ;
	ptr = (char *)str;
	while (*ptr != '\0')
	{
		ft_putchar(*ptr);
		ptr++;
	}
}
