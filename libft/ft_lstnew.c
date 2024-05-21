/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:08:24 by abeh              #+#    #+#             */
/*   Updated: 2024/05/21 23:14:08 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

int main()
{
    t_list *node = ft_lstnew("Hello, world!");

    if (node == NULL) // checks if the node is created successfully
    {
        printf("Failed to create a new node\n");
        return (1);
    }
    printf("Content of the node: %s\n", (char *)node->content);
    printf("Next of the node: %s\n", (char *)node->next);

    free(node);

    return (0);
}