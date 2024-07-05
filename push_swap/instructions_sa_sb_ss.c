/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_sa_sb_ss.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/07/05 17:00:24 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *s)
{
	t_elements	temp;

	if (s->a.size > 1)
	{
		temp = s->a.element[0];
		s->a.element[0] = s->a.element[1];
		s->a.element[1] = temp;
		ft_printf("sa\n");
	}
}
// int k = 0;
// ft_printf("\na\n");
// while (k < s->a.size)
// {
// 	ft_printf("%d %d\n", s->a.element[k].data, s->a.element[k].index);
// 	int o = 0;
// 	while (o < 9)
// 	{
// 		ft_printf("%d", s->a.element[k].bits[o]);
// 		o++;
// 	}
// 	ft_printf("\n");
// 	k++;
// }
// k = 0;
// ft_printf("\nb\n");
// while (k < s->b.size)
// {
// 	ft_printf("%d %d\n", s->b.element[k].data, s->b.element[k].index);
// 	k++;
// }

void	sb(t_stacks *s)
{
	t_elements	temp;

	if (s->b.size > 1)
	{
		temp = s->b.element[0];
		s->b.element[0] = s->b.element[1];
		s->b.element[1] = temp;
		ft_printf("sb\n");
	}
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

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
	ft_printf("ss\n");
}
