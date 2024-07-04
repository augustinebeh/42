/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/07/04 08:33:56 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

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
	int	max;
	int	i;

	if (is_sorted(s))
		return ;
	max = highest_int(s->a);
	i = s->a.size;
	while (i > 0)
	{
		if (s->a.element[0].index <= (max / 2))
			pb(s);
		else
			ra(s);
		i--;
	}
	swap_algo_three(s);
	if (s->b.element[0].index < s->b.element[1].index)
		sb(s);
	pa(s);
	pa(s);
	return ;
}
