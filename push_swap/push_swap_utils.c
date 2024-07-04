/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 07:36:20 by abeh              #+#    #+#             */
/*   Updated: 2024/07/04 09:27:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (0);
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stacks *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a.size)
	{
		j = i + 1;
		while (j < s->a.size)
		{
			if (s->a.element[i].data == s->a.element[j].data)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	highest_int(t_stack a)
{
	int	max;
	int	i;

	i = 0;
	max = a.element[0].index;
	while (i < a.size)
	{
		if (a.element[i].index > max)
			max = a.element[i].index;
		i++;
	}
	return (max);
}

int	lowest_int(t_stack a)
{
	int	min;
	int	i;

	i = 0;
	min = a.element[0].data;
	while (i < a.size)
	{
		if (a.element[i].data < min)
			min = a.element[i].data;
		i++;
	}
	return (min);
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->a.size - 1)
	{
		if (s->a.element[i].data > s->a.element[i + 1].data)
			return (0);
		i++;
	}
	return (1);
}
