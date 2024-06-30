/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:56:55 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 00:09:58 by abeh             ###   ########.fr       */
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
      if (s->a.element[i].data == biggest || s->a.element[i].data == smallest)
         ra(s);
      pb(s);
      j--;
   }
}
