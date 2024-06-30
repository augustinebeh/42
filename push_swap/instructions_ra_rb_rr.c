/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ra_rb_rr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:27 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 23:36:41 by abeh             ###   ########.fr       */
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

void	ra(stacks *s, int flag)
{
	elements	temp;
	int	i;

	if (s->a.size < 2)
		return;
	temp = s->a.element[0];
	i = 0;
	while (i < s->a.size - 1)
	{
		s->a.element[i] = s->a.element[i + 1];
		i++;
	}
	s->a.element[i] = temp;
	if (flag == 1)
		printf("ra\n");
	int k = 0;
	printf("\na\n");
	while (k < s->a.size)
	{
		printf("%d\n", s->a.element[k].data);
		k++;
	}
	k = 0;
	printf("\nb\n");
	while (k < s->b.size)
	{
		printf("%d\n", s->b.element[k].data);
		k++;
	}
	return;
}

void	rb(stacks *s, int flag)
{
	elements	temp;
	int	i;

	if (s->b.size < 2)
		return;
	temp = s->b.element[0];
	i = 0;
	while (i < s->b.size - 1)
	{
		s->b.element[i] = s->b.element[i + 1];
		i++;
	}
	s->b.element[i] = temp;
	if (flag == 1)
		printf("ra\n");
	int k = 0;
	printf("\na\n");
	while (k < s->a.size)
	{
		printf("%d\n", s->a.element[k].data);
		k++;
	}
	k = 0;
	printf("\nb\n");
	while (k < s->b.size)
	{
		printf("%d\n", s->b.element[k].data);
		k++;
	}
	return;
}

void	rr(stacks *s, int flag)
{
	ra(s, 0);
	rb(s, 0);
	printf("rr\n");
}
