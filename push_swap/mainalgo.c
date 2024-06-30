/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:56:55 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 02:31:13 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void mainalgo(stacks *s)
{
   int biggest;
   int smallest;

   biggest = highest_int(s->a);
   smallest = lowest_int(s->a);
   int i = 0;
   int j = s->a.size;

   while (j > 0)
   {
      if (!(s->a.element[i].data == biggest || s->a.element[i].data == smallest))
         pb(s);
      else
         ra(s);
      j--;
   }
   while (s->b.size != 0)
   {
      if ((s->b.element[0].data < s->a.element[0].data) && (s->b.element[0].data > s->a.element[s->a.size - 1].data))
         pa(s);
      else if ((s->b.element[0].data < s->a.element[0].data) && (s->b.element[0].data < s->a.element[s->a.size - 1].data))
         rra(s);
      else
         ra(s);
   }
   while (!if_sorted(s->a))
      ra(s);
}
