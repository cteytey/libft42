/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:22:19 by judehon           #+#    #+#             */
/*   Updated: 2025/10/23 15:38:18 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	len_d = 0;
	len_s = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	while (dst[len_d])
		len_d++;
	while (src[len_s])
		len_s++;
	if (size <= len_d)
		return (len_s + size);
	i = 0;
	j = len_d;
	while (src[i] && i < size - len_d - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_d + len_s);
}
