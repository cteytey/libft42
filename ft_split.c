/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:54 by judehon           #+#    #+#             */
/*   Updated: 2025/10/20 16:40:45 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	return (0);
}

static void	ft_free_all(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	ft_count_words(char const *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_is_sep(s[i], sep))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ft_is_sep(s[i], sep))
				i++;
		}
	}
	return (count);
}

static char	*ft_strduprange(char const *s, int min, int max)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (max - min + 1));
	if (!dest)
		return (0);
	while (i < max - min)
	{
		dest[i] = s[min + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	new = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_is_sep(s[i], c))
			i++;
		start = i;
		while (s[i] && !ft_is_sep(s[i], c))
			i++;
		if (start < i && !(new[j++] = ft_strduprange(s, start, i)))
			return (ft_free_all(new), NULL);
	}
	new[j] = NULL;
	return (new);
}
