/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 06:49:35 by abeh             ###   ########.fr       */
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
void	sa(int *stack_a, int *stack_b, int *ca, int *cb, int flag)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	if (flag == 1)
		printf("sa\n");
}

void	sb(int *stack_a, int *stack_b, int *ca, int *cb, int flag)
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	if (flag == 1)
		printf("sb\n");
}

void	ss(int *stack_a, int *stack_b, int *ca, int *cb, int flag)
{
	sa(stack_a, stack_b, ca, cb, 0);
	sb(stack_a, stack_b, ca, cb, 0);
	printf("ss\n");
}
