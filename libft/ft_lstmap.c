/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:13:47 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 13:56:50 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&new_lst, del);
			del(lst->content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, current);
		lst = lst->next;
	}
	return (new_lst);
}
