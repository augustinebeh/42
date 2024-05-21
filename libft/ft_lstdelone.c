/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:13:03 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 06:50:12 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function pointer
void	del(void *content)
{
	if (content)
	{
		content = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/* void print_list(t_list *lst)
{
    while (lst!= NULL)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}
int	main(void)
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    t_list *node3;
    t_list *node4;

    head = malloc(sizeof(t_list));
    node1 = malloc(sizeof(t_list));
    node2 = malloc(sizeof(t_list));
    node3 = malloc(sizeof(t_list));
    node4 = malloc(sizeof(t_list));

    head->content = "1st";
    head->next = node1;
    node1->content = "2nd";
    node1->next = node2;
    node2->content = "3rd";
    node2->next = node3;
    node3->content = "4th";
    node3->next = node4;
    node4->content = "5th";
    node4->next = NULL;
    printf("---------------------------\n");
    printf("----Before deleting 3rd----\n");
    printf("---------------------------\n");
    print_list(head);
    printf("--------------------------\n");
    printf("----After deleting 3rd----\n");
    printf("--------------------------\n");
    node1->next = node2->next; // update node1->next to point to node3
    ft_lstdelone(node2, del);
    print_list(head);
    t_list *current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }

    return (0);
} */