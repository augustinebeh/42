/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/07/04 07:25:44 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	swap_algo_three(t_stacks *s)
{
	int	max;

	if (is_sorted(s))
		return ;
	max = highest_int(s->a);
	if (s->a.element[0].index == max)
		ra(s);
	else if (s->a.element[1].index == max)
		rra(s);
	if (s->a.element[0].index > s->a.element[1].index)
		sa(s);
	return ;
}

void	swap_algo_five(t_stacks *s)
{
	if (is_sorted(s))
		return ;
	while (s->a.size != 3)
	{
		if (s->a.element[0].index < 3)
			pb(s);
		else
			ra(s);
	}
	swap_algo_three(s);
	if (s->b.element[0].index < s->b.element[1].index)
		sb(s);
	pa(s);
	pa(s);
}
