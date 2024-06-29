/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:26 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:48:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * RRA, RRB, RRR
 *--------------------------------------
 * RRA
 * Shifts all the ints of the stack A down by 1 position. The last int becomes the 1st.
 * RRB
 * Shifts all the ints of the stack B down by 1 position. The last int becomes the 1st.
 * RRR
 * Calls RA & RB simultaneously
 *--------------------------------------
 */

void rra(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int	temp;
   int	i;

   i = 0;
   if (*ca < 2)
      return;
   while (i < *ca)
      i++;
   temp = stack_a[i - 1];
   while (0 < i)
   {
      stack_a[i] = stack_a[i - 1];
      i--;
   }
   stack_a[0] = temp;
}

void rrb(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int	temp;
   int	i;
   int j;

   i = 0;
   j = 0;
   if (*cb < 2)
      return;
   while (i < *cb)
      i++;
   temp = stack_b[i - 1];
   while (0 < i)
   {
      stack_b[i] = stack_b[i - 1];
      i--;
   }
   stack_b[0] = temp;
}

void rrr(int *stack_a, int *stack_b, int *ca, int *cb)
{
   rra(stack_a, stack_b, ca, cb);
   rrb(stack_a, stack_b, ca, cb);
}
