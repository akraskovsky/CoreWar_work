/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:03:58 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/09 19:22:41 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	set;
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	set = (unsigned char)c;
	while (len--)
		*ptr++ = set;
	return (b);
}
