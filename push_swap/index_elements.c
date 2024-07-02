/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:04:58 by abeh              #+#    #+#             */
/*   Updated: 2024/07/03 06:10:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_elements *array, int size)
{
	int			i;
	t_elements	key;
	int			j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j].data > key.data)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

static void	copy_array(t_elements *array, t_elements *temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		temp[i] = array[i];
		i++;
	}
}

void	index_elements(t_elements *array, int size)
{
	int			i;
	int			j;
	t_elements	*temp;

	temp = (t_elements *)malloc(size * sizeof(t_elements));
	copy_array(array, temp, size);
	insertion_sort(temp, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i].data == temp[j].data)
			{
				array[i].index = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(temp);
}

void	append_bits(t_elements *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 9)
		{
			array[i].bits[j] = ((array[i].index >> j) & 1);
			j++;
		}
		i++;
	}
}
