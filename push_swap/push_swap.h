/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:45:45 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 08:56:30 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct {
	int	*data;
	int	size;
}		stack;


# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		highest_int(stack a);
int		lowest_int(stack a);
int		if_sorted(stack a);
int		has_duplicates(stack a);
int	is_valid_int(const char *str);


void	swap_algo_three(stack a, stack b);

void	pa(int *stack_a, int *stack_b, int *ca, int *cb);
void	pb(int *stack_a, int *stack_b, int *ca, int *cb);

void	sa(int *stack_a, int *stack_b, int *ca, int *cb, int flag);
void	sb(int *stack_a, int *stack_b, int *ca, int *cb, int flag);
void	ss(int *stack_a, int *stack_b, int *ca, int *cb, int flag);

void	ra(int *stack_a, int *ca, int flag);
void	rb(int *stack_b, int *cb, int flag);
void	rr(int *stack_a, int *stack_b, int *ca, int *cb, int flag);

void	rra(int *stack_a, int *stack_b, int *ca, int *cb, int flag);
void	rrb(int *stack_a, int *stack_b, int *ca, int *cb, int flag);
void	rrr(int *stack_a, int *stack_b, int *ca, int *cb, int flag);

#endif
