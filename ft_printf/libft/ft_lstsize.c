/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:12:24 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:09:15 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/* int main(void)
{
    // Create nodes for the linked list
    t_list *head = malloc(sizeof(t_list));
    head->content = "Hello";
    head->next = malloc(sizeof(t_list));
    head->next->content = "World";
    head->next->next = malloc(sizeof(t_list));
    head->next->next->content = "Goodbye";
    head->next->next->next = malloc(sizeof(t_list));
    head->next->next->next->content = "World";
    head->next->next->next->next = NULL;

    // Call ft_lstsize to get the size of the linked list
    int size = ft_lstsize(head);

    // Print the result
    printf("There are %d nodes in the list.\n", size);
    
    t_list *current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;   
    }
    return (0);
} */