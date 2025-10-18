/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:02:02 by judehon           #+#    #+#             */
/*   Updated: 2025/10/18 14:38:46 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	void			*res;

	if (nmemb != 0 && nmemb * size / nmemb != size)
		return (NULL);
	if (nmemb <= 0 || size <= 0)
	{
		tab = malloc(0);
		return (tab);
	}
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	res = ft_bzero(tab, nmemb * size);
	return (res);
}
