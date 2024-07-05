/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_pa_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:24 by abeh              #+#    #+#             */
/*   Updated: 2024/07/05 17:00:30 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *s)
{
	t_elements	temp;
	int			i;
	int			j;

	if (s->b.size < 1)
		return ;
	s->a.size = s->a.size + 1;
	s->b.size = s->b.size - 1;
	temp = s->b.element[0];
	i = 0;
	while (i < s->b.size)
	{
		s->b.element[i] = s->b.element[i + 1];
		i++;
	}
	j = s->a.size - 1;
	while (j > 0)
	{
		s->a.element[j] = s->a.element[j - 1];
		j--;
	}
	s->a.element[0] = temp;
	ft_printf("pa\n");
}
// int k = 0;
// ft_printf("\na\n");
// while (k < s->a.size)
// {
// 	ft_printf("%d %d\n", s->a.element[k].data, s->a.element[k].index);
// 	k++;
// }
// k = 0;
// ft_printf("\nb\n");
// while (k < s->b.size)
// {
// 	ft_printf("%d %d\n", s->b.element[k].data, s->b.element[k].index);
// 	k++;
// }

void	pb(t_stacks *s)
{
	t_elements	temp;
	int			i;
	int			j;

	if (s->a.size < 1)
		return ;
	s->b.size = s->b.size + 1;
	s->a.size = s->a.size - 1;
	temp = s->a.element[0];
	i = 0;
	while (i < s->a.size)
	{
		s->a.element[i] = s->a.element[i + 1];
		i++;
	}
	j = s->b.size - 1;
	while (j > 0)
	{
		s->b.element[j] = s->b.element[j - 1];
		j--;
	}
	s->b.element[0] = temp;
	ft_printf("pb\n");
}

// int k = 0;
// ft_printf("\na\n");
// while (k < s->a.size)
// {
// 	ft_printf("%d %d\n", s->a.element[k].data, s->a.element[k].index);
// 	k++;
// }
// k = 0;
// ft_printf("\nb\n");

// while (k < s->b.size)
// {
// 	// ft_printf("k = %d\n", k);
// 	ft_printf("%d %d\n", s->b.element[k].data, s->b.element[k].index);
// 	k++;
// }
