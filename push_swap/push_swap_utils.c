/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 07:36:20 by abeh              #+#    #+#             */
/*   Updated: 2024/07/01 00:33:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *str)
{
	int	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i]!= '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}

int	has_duplicates(stacks *s)
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

int	highest_int(stack a)
{
	int	max;

	max = a.element[0].data;
	for (int i = 1; i < a.size; i++)
	{
		if (a.element[i].data > max)
			max = a.element[i].data;
	}
	return (max);
}

int	lowest_int(stack a)
{
	int	min;

	min = a.element[0].data;
	for (int i = 1; i < a.size; i++)
	{
		if (a.element[i].data < min)
			min = a.element[i].data;
	}
	return (min);
}

int	if_sorted(stack a)
{
	int	sorted;

	sorted = 1;
	for (int i = 0; i < a.size - 1; i++)
	{
		if (a.element[i].data > a.element[i + 1].data)
		{
			sorted = 0;
			break ;
		}
	}
	return (sorted);
}
