/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:24 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 16:40:04 by abeh             ###   ########.fr       */
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
	temp = s->b.data[i];
	while (i < s->b.size)
	{
		s->b.data[i] = s->b.data[i + 1];
		i++;
	}
	while (j < s->a.size)
		j++;
	while (j > 0)
	{
		s->a.data[j] = s->a.data[j - 1];
		j--;
	}
	s->a.data[j] = temp;

	int k = 0;
	printf("pa\n");
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
}

void	pb(stacks *s)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s->a.size < 1)
		return ;
	s->b.size = s->b.size + 1;
	s->a.size = s->a.size - 1;
	temp = s->a.data[i];
	while (i < s->a.size)
	{
		s->a.data[i] = s->a.data[i + 1];
		i++;
	}
	while (j < s->b.size)
		j++;
	while (j > 0)
	{
		s->b.data[j] = s->b.data[j - 1];
		j--;
	}
	s->b.data[j] = temp;
	int k = 0;
	printf("pb\n");
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
}
