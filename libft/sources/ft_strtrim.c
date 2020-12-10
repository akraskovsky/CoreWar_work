/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:31:54 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/18 12:32:51 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	tail;
	size_t	len;
	char	*trim;
	char	*res;

	if (!s)
		return (NULL);
	trim = (char *)s;
	tail = 0;
	while (*trim == ' ' || *trim == '\n' || *trim == '\t')
		trim++;
	len = ft_strlen(trim);
	if (len > 0)
		while (trim[len - tail - 1] == ' ' || trim[len - tail - 1] == '\n' ||
				trim[len - tail - 1] == '\t')
			tail++;
	res = ft_strnew(len - tail);
	if (res != NULL)
		res = ft_strncpy(res, trim, len - tail);
	return (res);
}
