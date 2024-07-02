/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:45:45 by abeh              #+#    #+#             */
/*   Updated: 2024/07/02 08:33:27 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct elements
{
	int			data;
	int			index;
   int      bits[9];
}				elements;

typedef struct stack
{
	elements	*element;
	int			size;
}				stack;

typedef struct stacks
{
	stack		a;
	stack		b;
}				stacks;

int				highest_int(stack a);
int				lowest_int(stack a);
int				is_sorted(stacks *s);
int				has_duplicates(stacks *s);
int				is_valid_int(const char *str);

void			index_elements(elements *array, int size);
void			insertion_sort(elements *array, int size);
void 				append_bits(elements *array,int size);


void			swap_algo_three(stacks *s);
void 			swap_algo_five(stacks *s);

void			major_algo(stacks *s);

void			pa(stacks *s);
void			pb(stacks *s);

void			sa(stacks *s);
void			sb(stacks *s);
void			ss(stacks *s);

void			ra(stacks *s);
void			rb(stacks *s);
void			rr(stacks *s);

void			rra(stacks *s);
void			rrb(stacks *s);
void			rrr(stacks *s);

#endif
