/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 06:45:45 by abeh              #+#    #+#             */
/*   Updated: 2024/07/05 16:59:42 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_elements
{
	long		data;
	int			index;
	int			bits[9];
}				t_elements;

typedef struct t_stack
{
	t_elements	*element;
	int			size;
}				t_stack;

typedef struct t_stacks
{
	t_stack		a;
	t_stack		b;
}				t_stacks;

int				highest_int(t_stack a);
int				lowest_int(t_stack a);
int				is_sorted(t_stacks *s);
int				has_duplicates(t_stacks *s);
int				is_valid_int(const char *str);
long			ft_atoi(const char *c);

void			index_elements(t_elements *array, int size);
void			insertion_sort(t_elements *array, int size);
void			append_bits(t_elements *array, int size);

void			swap_algo_three(t_stacks *s);
void			swap_algo_five(t_stacks *s);

void			major_algo(t_stacks *s);

void			pa(t_stacks *s);
void			pb(t_stacks *s);

void			sa(t_stacks *s);
void			sb(t_stacks *s);
void			ss(t_stacks *s);

void			ra(t_stacks *s);
void			rb(t_stacks *s);
void			rr(t_stacks *s);

void			rra(t_stacks *s);
void			rrb(t_stacks *s);
void			rrr(t_stacks *s);

#endif
