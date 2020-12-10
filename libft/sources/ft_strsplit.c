/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:10:53 by fprovolo          #+#    #+#             */
/*   Updated: 2019/09/20 10:42:57 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_wordcount(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != '\0')
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
	}
	return (count);
}

char	**ft_fillwords(char **words, char *s, char c)
{
	size_t	word_count;
	size_t	word_len;

	word_count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			word_len = 0;
			while (s[word_len] != c && s[word_len] != '\0')
				word_len++;
			if (!(words[word_count] = ft_strsub(s, 0, word_len)))
			{
				while (word_count > 0)
					free(words[word_count-- - 1]);
				free(words);
				return (NULL);
			}
			s += word_len;
			word_count++;
		}
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_wordcount((char *)s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	words[word_count] = NULL;
	words = ft_fillwords(words, (char *)s, c);
	return (words);
}
