/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_sa_sb_ss.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/07/02 08:11:28 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * SA | SB | SS
 * -----------------------------------------
 * takes in  2 arrays of numbers.
 * one in stack 1 and one in stack 2
 * SA
 * swap the first 2 integers of stack A
 * SB
 * swap the first 2 integers of stack B
 * SS
 * Calls SA & SB simultaneously
 * -----------------------------------------
*/
#include "push_swap.h"

void	sa(stacks *s)
{
	if (s->a.size > 1)
	{
		elements	temp;

		temp = s->a.element[0];
		s->a.element[0] = s->a.element[1];
		s->a.element[1] = temp;
		printf("sa\n");
		// int k = 0;
		// printf("\na\n");
		// while (k < s->a.size)
		// {
		// 	printf("%d %d\n", s->a.element[k].data, s->a.element[k].index);
		// 	int o = 0;
		// 	while (o < 9)
		// 	{
		// 		printf("%d", s->a.element[k].bits[o]);
		// 		o++;

		// 	}
		// 	printf("\n");
		// 	k++;
		// }
		// k = 0;
		// printf("\nb\n");
		// while (k < s->b.size)
		// {
		// 	printf("%d %d\n", s->b.element[k].data, s->b.element[k].index);
		// 	k++;
		// }
	}
}

void	sb(stacks *s)
{
	if (s->b.size > 1)
	{
		elements	temp;

		temp = s->b.element[0];
		s->b.element[0] = s->b.element[1];
		s->b.element[1] = temp;
		printf("sb\n");
		// int k = 0;
		// printf("\na\n");
		// while (k < s->a.size)
		// {
		// 	printf("%d %d\n", s->a.element[k].data, s->a.element[k].index);
		// 	k++;
		// }
		// k = 0;
		// printf("\nb\n");
		// while (k < s->b.size)
		// {
		// 	printf("%d %d\n", s->b.element[k].data, s->b.element[k].index);
		// 	k++;
		// }
	}
}

void	ss(stacks *s)
{
	sa(s);
	sb(s);
	printf("ss\n");
}
