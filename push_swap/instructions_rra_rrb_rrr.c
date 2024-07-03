/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rra_rrb_rrr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:26 by abeh              #+#    #+#             */
/*   Updated: 2024/07/04 06:28:35 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

/**
 * RRA, RRB, RRR
 *--------------------------------------
 * RRA

	* Shifts all the ints of the stack A down by 1 position.
	The last int becomes the 1st.
 * RRB

	* Shifts all the ints of the stack B down by 1 position.
	The last int becomes the 1st.
 * RRR
 * Calls RA & RB simultaneously
 *--------------------------------------
 */

void	rra(t_stacks *s)
{
	t_elements	temp;
	int			i;

	i = 0;
	if (s->a.size < 2)
		return ;
	while (i < s->a.size)
		i++;
	temp = s->a.element[s->a.size - 1];
	i--;
	while (0 < i)
	{
		s->a.element[i] = s->a.element[i - 1];
		i--;
	}
	s->a.element[0] = temp;
	ft_printf("rra\n");
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

void	rrb(t_stacks *s)
{
	t_elements	temp;
	int			i;

	i = 0;
	if (s->b.size < 2)
		return ;
	while (i < s->b.size)
		i++;
	temp = s->b.element[s->b.size - 1];
	i--;
	while (0 < i)
	{
		s->b.element[i] = s->b.element[i - 1];
		i--;
	}
	s->b.element[0] = temp;
	ft_printf("rrb\n");
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

void	rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
	ft_printf("rrr\n");
	return ;
}
