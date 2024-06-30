/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:24 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 22:43:38 by abeh             ###   ########.fr       */
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
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s->b.size < 1)
		return ;
	s->a.size = s->a.size + 1;
	s->b.size = s->b.size - 1;
	temp = s->b.element[i].data;
	while (i < s->b.size)
	{
		s->b.element[i].data = s->b.element[i].data;
		i++;
	}
	while (j < s->a.size)
		j++;
	while (j > 0)
	{
		s->a.element[j].data = s->a.element[j - 1].data;
		j--;
	}
	s->a.element[j].data = temp;

	int k = 0;
	printf("pa\n");
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
}

void	pb(stacks *s)
{
	elements temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s->a.size < 1)
		return ;
	s->b.size = s->b.size + 1;
	s->a.size = s->a.size - 1;
	temp = s->a.element[i];
	while (i < s->a.size)
	{
		s->a.element[i] = s->a.element[i + 1];
		i++;
	}
	while (j < s->b.size - 1)
	{
		s->b.element[j] = s->b.element[j + 1];
		j++;
	}
	s->b.element[j] = temp;
	int k = 0;
	printf("pb\n");
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
}
