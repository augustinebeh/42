/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:27 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:14:54 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * RA, RB, RR
 *--------------------------------------
 * RA
 * Shifts all the elements of the stack a up by one position. The first element becomes the last.
 * RB
 * Shifts all the elements of the stack a up by one position. The first element becomes the last.
 * RR
 * Calls RA & RB simultaneously
 *--------------------------------------
 */
#include "push_swap.h"

void ra(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int	temp;
   int	i;

   if (*ca < 2)
      return;
   temp = stack_a[0];
   i = 0;
   while (i < *ca - 1)
   {
      stack_a[i] = stack_a[i + 1];
      i++;
   }
   stack_a[i] = temp;
}
void rb(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int	temp;
   int	i;

   if (*cb < 2)
      return;
   temp = stack_b[0];
   i = 0;
   while (i < *cb - 1)
   {
      stack_b[i] = stack_b[i + 1];
      i++;
   }
   stack_b[i] = temp;
}

void rr(int *stack_a, int *stack_b, int *ca, int *cb)
{
   ra(stack_a, stack_b, ca, cb);
   rb(stack_a, stack_b, ca, cb);
}
