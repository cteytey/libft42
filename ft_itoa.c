/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:03:01 by judehon           #+#    #+#             */
/*   Updated: 2025/10/17 13:39:03 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		len;
	int		is_neg;

	nb = n;
	is_neg = (nb < 0);
	if (nb < 0)
		nb = -nb;
	len = ft_intlen(nb) + is_neg;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > is_neg)
	{
		res[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
