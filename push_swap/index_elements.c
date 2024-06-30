/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:04:58 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 21:59:52 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(elements *array, int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        elements key = array[i];
        j = i - 1;
        while (j >= 0 && array[j].data > key.data)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void index_elements(elements *array, int size)
{
    int i = 0;
    elements temp[size];
    while (i < size)
    {
        temp[i] = array[i];
        i++;
    }
    insertion_sort(temp, size);

    i = 0;
    int j = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (array[i].data == temp[j].data)
            {
                array[i].index = j + 1;
                break;
            }
            j++;
        }
        i++;
    }
}
