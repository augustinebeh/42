/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 07:59:25 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap_algo_three(stack a, stack b)
{
    if (if_sorted(a))
        return;
    int max = highest_int(a);
    if (a.data[0] == max)
        ra(a.data, &a.size, 1);
    else if (a.data[1] == max)
        rra(a.data, b.data, &a.size, &b.size, 1);
    if (a.data[0] > a.data[1])
        sa(a.data, b.data, &a.size, &b.size, 1);
}
