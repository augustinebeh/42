/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 04:35:46 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 06:48:02 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int highest_int(stack a)
{
    int max = a.data[0];
    for (int i = 1; i < a.size; i++) {
        if (a.data[i] > max)
            max = a.data[i];
    }
    return max;
}

void swap_algo_three(stack a, stack b)
{
   int max = highest_int(a);
   if (a.data[0] == max)
      rr(a.data, b.data, &a.size, &b.size, 1);
   else if (a.data[1] == max)
      rra(a.data, b.data, &a.size, &b.size, 1);
   if (a.data[0] > a.data[1])
      sa(a.data, b.data, &a.size, &b.size, 1);
}
