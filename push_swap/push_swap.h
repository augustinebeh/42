/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:45:45 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 17:15:07 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct
{
	int		*data;
	int		size;
}			stack;

typedef struct
{
	stack	a;
	stack	b;
}			stacks;

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			highest_int(stack a);
int			lowest_int(stack a);
int			if_sorted(stack a);
int			has_duplicates(stacks *s);
int			is_valid_int(const char *str);

void		swap_algo_three(stacks *s);
void		swap_algo_four(stacks *s);

void		pa(stacks *s);
void		pb(stacks *s);

void		sa(stacks *s, int flag);
void		sb(stacks *s, int flag);
void		ss(stacks *s, int flag);

void		ra(stacks *s, int flag);
void		rb(stacks *s, int flag);
void		rr(stacks *s, int flag);

void		rra(stacks *s, int flag);
void		rrb(stacks *s, int flag);
void		rrr(stacks *s, int flag);

#endif
