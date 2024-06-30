/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ra_rb_rr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:27 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 16:01:47 by abeh             ###   ########.fr       */
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
	int	temp;
	int	i;

	if (s->a.size < 2)
		return;
	temp = s->a.data[0];
	i = 0;
	while (i < s->a.size - 1)
	{
		s->a.data[i] = s->a.data[i + 1];
		i++;
	}
	s->a.data[i] = temp;
	if (flag == 1)
		printf("ra\n");
	printf("%d\n%d\n%d\n", s->a.data[0], s->a.data[1], s->a.data[2]);
	return;
}

void	rb(stacks *s, int flag)
{
	int	temp;
	int	i;

	if (s->b.size < 2)
		return;
	temp = s->b.data[0];
	i = 0;
	while (i < s->b.size - 1)
	{
		s->b.data[i] = s->b.data[i + 1];
		i++;
	}
	s->b.data[i] = temp;
	if (flag == 1)
		printf("ra\n");
	printf("%d\n%d\n%d\n", s->a.data[0], s->a.data[1], s->a.data[2]);
	return;
}

void	rr(stacks *s, int flag)
{
	ra(s, 0);
	rb(s, 0);
	printf("rr\n");
}
