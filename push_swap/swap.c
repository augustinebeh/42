/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:43:28 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:10:53 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * SA | SB | SS
 * -----------------------------------------
 * takes in  2 arrays of numbers.
 * one in stack 1 and one in stack 2
 * SA
 * swap the first 2 integers of stack A
 * SB
 * swap the first 2 integers of stack B
 * SS
 * Calls SA & SB simultaneously
 * -----------------------------------------
*/

void sa(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int temp;

   temp = stack_a[0];
   stack_a[0] = stack_a[1];
   stack_a[1] = temp;
}

void sb(int *stack_a, int *stack_b, int *ca, int *cb)
{
   int temp;

   temp = stack_b[0];
   stack_b[0] = stack_b[1];
   stack_b[1] = temp;
}

void ss(int *stack_a, int *stack_b, int *ca, int *cb)
{
   sa(stack_a, stack_b, ca, cb);
   sb(stack_a, stack_b, ca, cb);
}
