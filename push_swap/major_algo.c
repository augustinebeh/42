/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:56:55 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 21:08:01 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int power(int x, int y)
{
   while (y > 0)
   {
      x = x * x;
      y--;
   }
   return x;
}

void major_algo(stacks *s) {
    while (is_sorted(s) == 0) {
        while (s->a.size > 1 && s->a.element[s->a.size - 1].data < s->a.element[s->a.size - 2].data) {
            sa(s);
        }
        if (s->a.size > 1 && s->a.element[s->a.size - 1].data > s->a.element[s->a.size - 2].data) {
            pb(s);
            while (s->b.size > 1 && s->b.element[s->b.size - 1].data < s->b.element[s->b.size - 2].data) {
                sb(s);
            }
            pa(s);
        }
    }
}
