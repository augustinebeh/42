/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:45:45 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:34:41 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void pa(int *stack_a, int *stack_b, int *ca, int *cb);
void pb(int *stack_a, int *stack_b, int *ca, int *cb);
void sa(int *stack_a, int *stack_b, int *ca, int *cb);
void sb(int *stack_a, int *stack_b, int *ca, int *cb);
void ss(int *stack_a, int *stack_b, int *ca, int *cb);
void ra(int *stack_a, int *stack_b, int *ca, int *cb);
void rr(int *stack_a, int *stack_b, int *ca, int *cb);
void rb(int *stack_a, int *stack_b, int *ca, int *cb);
void rra(int *stack_a, int *stack_b, int *ca, int *cb);
void rrb(int *stack_a, int *stack_b, int *ca, int *cb);
void rrr(int *stack_a, int *stack_b, int *ca, int *cb);


#endif
