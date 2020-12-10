/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:28:47 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/18 12:28:56 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr_c;

	ptr = (char *)s;
	ptr_c = NULL;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			ptr_c = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (ptr_c);
}
