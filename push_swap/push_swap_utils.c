/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 07:36:20 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 08:38:13 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_int(const char *str)
{
	int	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i]!= '\0')
	{
		if (!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int	has_duplicates(stack a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size)
	{
		j = i + 1;
		while (j < a.size)
		{
			if (a.data[i] == a.data[j])
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

	max = a.data[0];
	for (int i = 1; i < a.size; i++)
	{
		if (a.data[i] > max)
			max = a.data[i];
	}
	return (max);
}

int	lowest_int(stack a)
{
	int	min;

	min = a.data[0];
	for (int i = 1; i < a.size; i++)
	{
		if (a.data[i] < min)
			min = a.data[i];
	}
	return (min);
}

int	if_sorted(stack a)
{
	int	sorted;

	sorted = 1;
	for (int i = 0; i < a.size - 1; i++)
	{
		if (a.data[i] > a.data[i + 1])
		{
			sorted = 0;
			break ;
		}
	}
	return (sorted);
}
