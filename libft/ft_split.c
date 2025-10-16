/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:54 by judehon           #+#    #+#             */
/*   Updated: 2025/10/16 16:02:11 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strduprange(char const *s, int min, int max);

static int	is_sep(char c, char sep);

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	bp;
	size_t	j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * ft_strlen(s));
	if (!new)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		bp = i;
		while (s[i] && !is_sep(s[i], c))
			i++;
		if (bp < i)
		{
			new[j] = ft_strduprange(s, bp, i);
			j++;
		}
	}
	new[j] = NULL;
	return (new);
}

static char	*ft_strduprange(char const *s, int min, int max)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (max - min + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < max - min)
	{
		dest[i] = s[min + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	is_sep(char c, char sep)
{
	if (sep == c)
		return (1);
	else
		return (0);
}
