/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:24 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 02:01:32 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * --------------------------------
 * PA
 * moves the first int of B to A
 * PB
 * moves the first int from A to B
 * --------------------------------
 */

#include "push_swap.h"

void	pa(stacks *s)
{
	elements temp;
	int	i;
	int	j;

	i = 0;
	j = s->a.size;
	if (s->b.size < 1)
		return ;
	s->a.size = s->a.size + 1;
	s->b.size = s->b.size - 1;
	temp = s->b.element[0];
	while (i < s->b.size)
	{
		s->b.element[i] = s->b.element[i + 1];
		i++;
	}
	while (j > 0)
	{
		s->a.element[j] = s->a.element[j - 1];
		j--;
	}
	s->a.element[0] = temp;
	printf("pa\n");
	// int k = 0;
	// printf("\na\n");
	// while (k < s->a.size)
	// {
	// 	printf("%d\n", s->a.element[k].data);
	// 	k++;
	// }
	// k = 0;
	// printf("\nb\n");
	// while (k < s->b.size)
	// {
	// 	printf("%d\n", s->b.element[k].data);
	// 	k++;
	// }
}

void	pb(stacks *s)
{
	elements temp;
	int	i;
	int	j;

	i = 0;
	j = s->b.size;
	if (s->a.size < 1)
		return ;
	s->b.size = s->b.size + 1;
	s->a.size = s->a.size - 1;
	temp = s->a.element[0];
	while (i < s->a.size)
	{
		s->a.element[i] = s->a.element[i + 1];
		i++;
	}
	while (j > 0)
	{
		s->b.element[j] = s->b.element[j - 1];
		j--;
	}
	s->b.element[0] = temp;
	printf("pb\n");
	// int k = 0;
	// printf("\na\n");
	// while (k < s->a.size)
	// {
	// 	printf("%d\n", s->a.element[k].data);
	// 	k++;
	// }
	// k = 0;
	// printf("\nb\n");

	// while (k < s->b.size)
	// {
	// 	printf("%d\n", s->b.element[k].data);
	// 	k++;
	// }
}
