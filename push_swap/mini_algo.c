/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 21:10:20 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_algo_three(stacks *s)
{
    if (is_sorted(s))
        return;
    int max = highest_int(s->a);
    if (s->a.element[0].data == max)
        ra(s);
    else if (s->a.element[1].data == max)
        rra(s);
    if (s->a.element[0].data > s->a.element[1].data)
        sa(s);
}

void swap_algo_five(stacks *s)
{
    if (is_sorted(s))
        return;
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
