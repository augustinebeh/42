/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:24 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:30:36 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * --------------------------------
 * PA
 * moves the first int of B to A
 * PB
 * moves the first int from A to B
 * --------------------------------
 */

void pa(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int temp;
   int i = 0;
   int j = 0;

   if (*cb < 1)
      return;
   *ca = *ca + 1;
   *cb = *cb - 1;
   temp = stack_b[i];
   while (i < *cb)
   {
      stack_b[i] = stack_b[i+1];
      i++;
   }
   while (j < *ca)
      j++;

   while (j > 0)
   {
      stack_a[j] = stack_a[j-1];
      j--;
   }
   stack_a[j] = temp;
}

void pb(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int temp;
   int i = 0;
   int j = 0;

   if (*ca < 1)
      return;
   *cb = *cb + 1;
   *ca = *ca - 1;
   temp = stack_a[i];
   while (i < *ca)
   {
      stack_a[i] = stack_a[i+1];
      i++;
   }
   while (j < *cb)
      j++;

   while (j > 0)
   {
      stack_b[j] = stack_b[j-1];
      j--;
   }
   stack_b[j] = temp;
}
