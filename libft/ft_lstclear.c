/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 03:13:24 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 05:46:12 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_lst;

	current = *lst;
	while (current != NULL)
	{
		next_lst = current->next;
		del(current);
		current = next_lst;
	}
	*lst = NULL;
}

/* static void	del_content(void *content)
{
	if (content)
		free(content);
}

static void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int main() {
  t_list *list = NULL;
  t_list *node1 = malloc(sizeof(t_list));
  t_list *node2 = malloc(sizeof(t_list));
  t_list *node3 = malloc(sizeof(t_list));

  node1->content = "Hello";
  node2->content = "World";
  node3->content = "!!!";

  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  list = node1;

  printf("Before clearing the list:\n");
  t_list *current = list;
  while (current) {
    printf("Node content: %s\n", (char*)current->content);
    current = current->next;
  }

  ft_lstclear(&list, del_content);

  printf("After clearing the list:\n");
  current = list;
  while (current) {
    printf("Node content: %s\n", (char*)current->content);
    current = current->next;
  }

  return (0);
} */