/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/06/20 12:32:02 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

stack_a	*ft_lstnew(void *content)
{
	stack_a	*newnode;

	newnode = ft_malloc(sizeof(stack_a));

	if (newnode == NULL)
		return (NULL);
	newnode->num = content;
	newnode->next = NULL;
	return (newnode);
}

int main(int ac, char **av)
{
   int i = 0;

	char *arr[] = ft_split(av[1], ' ');

	while (arr[i])
	{
		printf("%s\n", arr[i]);
	}

}
