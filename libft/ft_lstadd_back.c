/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:12:51 by abeh              #+#    #+#             */
/*   Updated: 2024/05/21 23:11:34 by abeh             ###   ########.fr       */
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
int main(void)
{
    t_list *head;
    t_list *body1;
    t_list *body2;
    t_list *tail;
    t_list *toadd;
    
    head = malloc(sizeof(t_list));
    head->content = "head";
    body1 = malloc(sizeof(t_list));
    body1->content = "body1";
    head->next = body1;
    body2 = malloc(sizeof(t_list));
    body2->content = "body2";
    body1->next = body2;
    tail = malloc(sizeof(t_list));
    tail->content = "tail";
    body2->next = tail;
    tail->next = NULL;
    
    toadd = malloc(sizeof(t_list));
    toadd->content = "toadd";
    toadd->next = NULL;

    ft_lstadd_back(&head, toadd);
    t_list *current;
    current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("Content in node %d is: %s\n", i, (char *)current->content);
        current = current->next;
        i++;
    }
    current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
    return 0;
}