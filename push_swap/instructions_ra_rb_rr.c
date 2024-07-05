/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ra_rb_rr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:27 by abeh              #+#    #+#             */
/*   Updated: 2024/07/05 17:00:16 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *s)
{
	t_elements	temp;
	int			i;

	if (s->a.size < 2)
		return ;
	temp = s->a.element[0];
	i = 0;
	while (i < s->a.size - 1)
	{
		s->a.element[i] = s->a.element[i + 1];
		i++;
	}
	s->a.element[i] = temp;
	ft_printf("ra\n");
}
// int k = 0;
// ft_printf("\na\n");
// while (k < s->a.size)
// {
// 	ft_printf("%d\n", s->a.element[k].data);
// 	k++;
// }
// k = 0;
// ft_printf("\nb\n");
// while (k < s->b.size)
// {
// 	ft_printf("%d\n", s->b.element[k].data);
// 	k++;
// }
// return ;

void	rb(t_stacks *s)
{
	t_elements	temp;
	int			i;

	if (s->b.size < 2)
		return ;
	temp = s->b.element[0];
	i = 0;
	while (i < s->b.size - 1)
	{
		s->b.element[i] = s->b.element[i + 1];
		i++;
	}
	s->b.element[i] = temp;
	ft_printf("rb\n");
}
// int k = 0;
// ft_printf("\na\n");
// while (k < s->a.size)
// {
// 	ft_printf("%d\n", s->a.element[k].data);
// 	k++;
// }
// k = 0;
// ft_printf("\nb\n");
// while (k < s->b.size)
// {
// 	ft_printf("%d\n", s->b.element[k].data);
// 	k++;
// }
// return ;

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
	ft_printf("rr\n");
}
