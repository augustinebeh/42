/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 18:46:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_algo_three(stacks *s)
{
    if (if_sorted(s->a))
        return;
    int max = highest_int(s->a);
    if (s->a.data[0] == max)
        ra(s, 1);
    else if (s->a.data[1] == max)
        rra(s, 1);
    if (s->a.data[0] > s->a.data[1])
        sa(s, 1);

}

void swap_algo_four(stacks *s)
{
    if (if_sorted(s->a))
        return;
    pb(s);
    swap_algo_three(s);
    while (s->b.size > 0)
    {
        int found_larger = 0;
        int temp = s->a.size;
        while (temp > 1)
        {
            if (s->a.data[temp - 1] > s->b.data[0])
            {
                found_larger = 1;
                break;
            }
            ra(s, 1);
            temp--;
        }
        if (!found_larger)
        {
            while (s->a.size > 1)
            {
                rra(s, 1);
            }
        }
        pa(s);
    }
}
