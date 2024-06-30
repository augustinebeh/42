/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ra_rb_rr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:27 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 07:58:38 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * RA, RB, RR
 *--------------------------------------
 * RA

	* Shifts all the elements of the stack a up by one position.
	The first element becomes the last.
 * RB

	* Shifts all the elements of the stack a up by one position.
	The first element becomes the last.
 * RR
 * Calls RA & RB simultaneously
 *--------------------------------------
 */
#include "push_swap.h"

void	ra(int *stack_a, int *ca, int flag)
{
	int	temp;
	int	i;

	if (*ca < 2)
		return;
	temp = stack_a[0];
	i = 0;
	while (i < *ca - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	if (flag == 1)
		printf("ra\n");
	return;
}

void	rb(int *stack_b, int *cb, int flag)
{
	int	temp;
	int	i;

	if (*cb < 2)
		return;
	temp = stack_b[0];
	i = 0;
	while (i < *cb - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = temp;
	if (flag == 1)
		printf("ra\n");
	return;
}

void	rr(int *stack_a, int *stack_b, int *ca, int *cb, int flag)
{
	ra(stack_a, ca, 0);
	rb(stack_b, cb, 0);
	printf("rr\n");
}
