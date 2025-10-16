/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:36:00 by judehon           #+#    #+#             */
/*   Updated: 2025/10/14 18:42:13 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	size_t			i;

	i = 0;
	sptr = (unsigned char *)s;
	while (i < n)
	{
		if (sptr[i] == c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}
