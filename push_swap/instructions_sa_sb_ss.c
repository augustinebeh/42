/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_sa_sb_ss.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 00:18:05 by abeh             ###   ########.fr       */
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
	int	temp;

	temp = s->a.element[0].data;
	s->a.element[0].data = s->a.element[1].data;
	s->a.element[1].data = temp;
	printf("sa\n");
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

void	sb(stacks *s)
{
	int	temp;

	temp = s->b.element[0].data;
	s->b.element[0].data = s->b.element[1].data;
	s->b.element[1].data = temp;
	printf("sb\n");
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

void	ss(stacks *s)
{
	sa(s);
	sb(s);
	printf("ss\n");
}
