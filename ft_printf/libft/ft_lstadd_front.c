/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:11:52 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:19:44 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main()
{
    // Initialize two nodes with some data
    t_list *node1;
    t_list *node2;
    
    node1 = malloc(sizeof(t_list));
    node2 = malloc(sizeof(t_list));
    node1->content = "Hello";
    node2->content = "World";

    // Add node2 to node1
    ft_lstadd_front(&node1, node2);

    // Print the data of each node in the list
    t_list *current = node1;
    int i = 1;
    while (current!= NULL)
    {
        printf("Content in node %d is:  %s\n", i, (char *)current->content);
        current = current->next;
        i++;
    }

    // Free the memory allocated for the nodes
    current = node1;
    while (current->next)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
    free(current);

    return (0);
} */