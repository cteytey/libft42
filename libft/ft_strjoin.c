/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:28:42 by judehon           #+#    #+#             */
/*   Updated: 2025/10/15 16:56:21 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*final_str;

	len = ft_strlen(s1) + ft_strlen(s2);
	final_str = malloc(sizeof(char) * len + 1);
	if (!final_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_str[i + j] = s2[j];
		j++;
	}
	return (final_str);
}
