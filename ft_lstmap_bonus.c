/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:16:41 by judehon           #+#    #+#             */
/*   Updated: 2025/10/18 19:03:13 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*data;

	if (!lst)
		return (NULL);
	new = malloc(sizeof(t_list) * ft_lstsize(lst));
	if (!new)
		return (NULL);
	while (lst)
	{
		data = f(lst->content);
		tmp = ft_lstnew(data);
		if (!tmp)
		{
			del(data);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst -> next;
	}
	return (new);
}