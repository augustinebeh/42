/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rra_rrb_rrr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:26 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 00:17:30 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * RRA, RRB, RRR
 *--------------------------------------
 * RRA

	* Shifts all the ints of the stack A down by 1 position.
	The last int becomes the 1st.
 * RRB

	* Shifts all the ints of the stack B down by 1 position.
	The last int becomes the 1st.
 * RRR
 * Calls RA & RB simultaneously
 *--------------------------------------
 */

void	rra(stacks *s)
{
	int	temp;
	int	i;

	i = 0;
	if (s->a.size < 2)
		return;
	while (i < s->a.size)
		i++;
	temp = s->a.element[i - 1].data;
	while (0 < i)
	{
		s->a.element[i].data = s->a.element[i - 1].data;
		i--;
	}
	s->a.element[0].data = temp;
	printf("rra\n");
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
	// return;
}

void	rrb(stacks *s)
{
	int	temp;
	int	i;

	i = 0;
	if (s->b.size < 2)
		return;
	while (i < s->b.size)
		i++;
	temp = s->b.element[i - 1].data;
	while (0 < i)
	{
		s->b.element[i].data = s->b.element[i - 1].data;
		i--;
	}
	s->b.element[0].data = temp;
	printf("rrb\n");
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
	// return;
}

void	rrr(stacks *s)
{
	rra(s);
	rrb(s);
	printf("rrr\n");
	return;
}
