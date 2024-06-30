/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_sa_sb_ss.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 16:41:22 by abeh             ###   ########.fr       */
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

// problem i am facing now is that when ss is called
// all 3 instructions will be printed.
// find a way to resolve this issue
void	sa(stacks *s, int flag)
{
	int	temp;

	temp = s->a.data[0];
	s->a.data[0] = s->a.data[1];
	s->a.data[1] = temp;
	if (flag == 1)
		printf("\nsa\n");
	int k = 0;
	printf("\na\n");
	while (k < s->a.size)
	{
		printf("%d\n", s->a.data[k]);
		k++;
	}
	k = 0;
	printf("\nb\n");

	while (k < s->b.size)
	{
		printf("%d\n", s->b.data[k]);
		k++;
	}
	return;

}

void	sb(stacks *s, int flag)
{
	int	temp;

	temp = s->b.data[0];
	s->b.data[0] = s->b.data[1];
	s->b.data[1] = temp;
	if (flag == 1)
		printf("\nsb\n");
	int k = 0;
	printf("\na\n");
	while (k < s->a.size)
	{
		printf("%d\n", s->a.data[k]);
		k++;
	}
	k = 0;
	printf("\nb\n");

	while (k < s->b.size)
	{
		printf("%d\n", s->b.data[k]);
		k++;
	}
	return;
}

void	ss(stacks *s, int flag)
{
	sa(s, 0);
	sb(s, 0);
	printf("ss\n");
}
