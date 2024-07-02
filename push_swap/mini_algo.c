/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/07/03 06:13:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_algo_three(t_stacks *s)
{
	if (is_sorted(s))
		return;
	if (s->a.element[0].index == 3)
		ra(s);
	else if (s->a.element[1].index == 3)
		rra(s);
	if (s->a.element[0].index > s->a.element[1].index)
		sa(s);
	return;
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
