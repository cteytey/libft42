/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:54 by judehon           #+#    #+#             */
/*   Updated: 2025/10/17 16:32:24 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char set);

static int	ft_word_len(char const *s, char set);

static char	*ft_add_word(char const *s, int size);

static int	ft_is_sep(char c, char sep);

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	**new;
	int		word_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	word_len = 0;
	count_words = ft_count_words(s, c);
	new = malloc(sizeof(char *) * (count_words + 1));
	if (!new)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && ft_is_sep(s[i], c))
			i++;
		word_len = ft_word_len(&s[i], c);
		if (word_len)
			new[j++] = ft_add_word(&s[i], word_len);
		i += word_len;
		word_len = 0;
	}
	new[j] = NULL;
	return (new);
}

static int	ft_is_sep(char c, char set)
{
	if (set == c)
		return (1);
	return (0);
}

static char	*ft_add_word(char const *s, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (0);
	while (s[i] && i < size)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_word_len(char const *s, char set)
{
	int	i;

	i = 0;
	while (s[i] && !ft_is_sep(s[i], set))
		i++;
	return (i);
}

static int	ft_count_words(char const *s, char set)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (s[i] != '\0')
	{
		while (s[i] && ft_is_sep(s[i], set))
			i++;
		word_len = ft_word_len(&s[i], set);
		if (word_len)
			count++;
		i += word_len;
		word_len = 0;
	}
	return (count);
}
