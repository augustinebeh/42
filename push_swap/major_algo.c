/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:56:55 by abeh              #+#    #+#             */
/*   Updated: 2024/07/02 09:01:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void major_algo(stacks *s)
{
    int i;
    int j;
    int k;
    int size = s->a.size;

    i = 0;
    while (1)
    {
        j = 0;
        while (size > j)
        {
            if (s->a.element[0].bits[i] == 0)
                pb(s);
            else
                ra(s);
            j++;
        }
        k = s->b.size;
        while (k-- > 0)
            pa(s);
        if (is_sorted(s) && s->b.size == 0)
            return;
        i++;
    }
}
