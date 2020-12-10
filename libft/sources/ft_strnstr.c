/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:09:01 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/18 12:30:11 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr1;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	ptr1 = (char *)haystack;
	while (*ptr1 != '\0')
	{
		i = 0;
		while (needle[i] == *(ptr1 + i) && (size_t)(ptr1 - haystack + i) < len)
		{
			i++;
			if (needle[i] == '\0')
				return (ptr1);
		}
		ptr1++;
	}
	return (NULL);
}
