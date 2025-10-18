/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:54:11 by judehon           #+#    #+#             */
/*   Updated: 2025/10/17 13:00:38 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	if (dest == src || n == 0)
		return (dest);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (t_dest > t_src)
	{
		while (n--)
			t_dest[n] = t_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
	return (dest);
}
