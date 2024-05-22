/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:12:51 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 23:13:29 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;

    if (!*lst || new == NULL)
        return;
    temp = *lst;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->next = NULL;
}
/* static void print_list(t_list *lst)
{
    int i;

    i = 1;
    while (lst!= NULL)
    {
        printf("Content of node %d is: %s\n", i, (char *)lst->content);
        lst = lst->next;
        i++;
    }
}

int	main(void)
{
	t_list *head;
	t_list *body;
	t_list *body2;
	t_list *tail;
	t_list *toadd;

	head = malloc(sizeof(t_list));
	body = malloc(sizeof(t_list));
	tail = malloc(sizeof(t_list));
	toadd = malloc(sizeof(t_list));
    
	head->content = "head";
	body->content = "body";
	tail->content = "tail";
	head->next = body;
	body->next = tail;
	tail->next = NULL;

	toadd->content = "new node";
	toadd->next = NULL;
    
    printf("----------------------------\n");
    printf("-------INTITIAL NODES-------\n");
    printf("----------------------------\n");
    
    print_list(head);
    
    printf("----------------------------\n");
    printf("----NODES AFTER FUNCTION----\n");
    printf("----------------------------\n");

	ft_lstadd_back(&head, toadd);
	t_list *current;
	print_list(head);
    printf("----------------------------\n");

	current = head;
	while (current)
	{
		t_list *next = current->next;
		free(current);
		current = next;
	}
	return (0);
} */