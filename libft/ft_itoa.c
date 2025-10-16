/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:03:01 by judehon           #+#    #+#             */
/*   Updated: 2025/10/16 16:45:23 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int	i;
	char	*str;

	if (n == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	i = ft_intlen(n);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		i--;
		str[i] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
