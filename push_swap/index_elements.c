/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 19:04:58 by abeh              #+#    #+#             */
/*   Updated: 2024/07/02 08:33:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion_sort(elements *array, int size)
{
    int i = 1;
    while (i < size)
    {
        elements key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].data > key.data)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
        i++;
    }
}

void index_elements(elements *array, int size)
{
    int i;
    int j;

    i = 0;
    elements temp[size];
    while (i < size)
    {
        temp[i] = array[i];
        i++;
    }
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
                break;
            }
            j++;
        }
        i++;
    }
}

void append_bits(elements *array, int size)
{
    int i = 0;

    while (i < size)
    {
        int j = 0;
        while (j < 9)
        {
            array[i].bits[j] = ((array[i].index >> j) & 1);
            j++;
        }
        i++;
    }
}
