/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:51:45 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/18 12:31:08 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr1;
	int		i;

	if (*needle == '\0')
		return ((char *)haystack);
	ptr1 = (char *)haystack;
	while (*ptr1 != '\0')
	{
		i = 0;
		while (needle[i] == *(ptr1 + i))
		{
			i++;
			if (needle[i] == '\0')
				return (ptr1);
		}
		ptr1++;
	}
	return (NULL);
}
