/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:32:06 by judehon           #+#    #+#             */
/*   Updated: 2025/10/16 17:23:23 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;
	size_t			i;

	i = 0;
	if (!src)
		return (NULL);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (t_dest > t_src)
		ft_memmove(dest, src, n);
	else
	{
		while (i < n)
		{
			t_dest[i] = t_src[i];
			i++;
		}
	}
	return (dest);
}
