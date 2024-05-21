/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:12:38 by abeh              #+#    #+#             */
/*   Updated: 2024/05/21 23:13:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    while (lst->next)
        lst = lst->next;
    return(lst);
}   
int main(void)
{
    t_list *head;
    t_list *node1;
    t_list *node2;
    t_list *current;
    // creation of a few nodes.
    head = malloc(sizeof(t_list));
    head->content = "*contents of the first node*";
    node1 = malloc(sizeof(t_list));
    node1->content = "*contents of the middle node";
    head->next = node1;
    node2 = malloc(sizeof(t_list));
    node2->content = "*contents of the last node*";
    node1->next = node2;
    node2->next = NULL;
    // prints the last node of the list using ft_lstlast function
    printf("The content of the last node is: %s\n", (char *)ft_lstlast(head)->content);
    current = head;
    while (current)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
    return (0);
}