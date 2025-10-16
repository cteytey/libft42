/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:58:17 by judehon           #+#    #+#             */
/*   Updated: 2025/10/15 17:51:24 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(set);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i])
	{
		while (s1[i] == set[j])
		{
			i++;
			j++;
		}
		res[k] = s1[i];
		i++;
		k++;
	}
	return (res);
}
int	main(int ac, char **av)
{
	ac++;
	char *res = ft_strtrim(av[1], av[2]);
	printf("%s\n", res);
	free(res);
}