/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 00:11:25 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_algo_three(stacks *s)
{
    if (if_sorted(s->a))
        return;
    int max = highest_int(s->a);
    if (s->a.element[0].data == max)
        ra(s);
    else if (s->a.element[1].data == max)
        rra(s);
    if (s->a.element[0].data > s->a.element[1].data)
        sa(s);

}
