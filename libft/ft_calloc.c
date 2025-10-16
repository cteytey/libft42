/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:02:02 by judehon           #+#    #+#             */
/*   Updated: 2025/10/15 16:52:40 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	return (ft_bzero(tab, nmemb * size));
}
