/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:34:50 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 05:43:39 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// BASICALLY, CALLOC IS MALLOC BUT MEMSETS THE ALLOCATED MEMORY TO "0"
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/* int main()
{
    int *array;
    size_t nmemb = 3;
    size_t size = sizeof(int);
    size_t i = 0;

    array = (int *)malloc(nmemb*size); //allocates a memory to array
    if (array == NULL)
    {
        printf("Memory alloc failed!\n");
        return (1);
    }
    printf(" ------------------\n");
    printf("|   AFTER MALLOC   |\n");
    printf(" ------------------\n");
    i = 0;
     while (i < nmemb) //prints out the values of all the elements
    {
        printf("Array element %zu is %d\n", i, array[i]);
        i++;
    }
    
    printf(" ------------------\n");
    printf("|  EDITTED MALLOC  |\n");
    printf(" ------------------\n");
    i = 0;
    while (i < 8) // give all elment in the array the value of 1
    {
        array[i] = 1;
        i++;
    }
    i = 0;
    while (i < nmemb) //prints out the values of all the elements
    {
        printf("Array element %zu is %d\n", i, array[i]);
        i++;
    }
    printf(" ------------------\n");
    printf("|   AFTER CALLOC   |\n");
    printf(" ------------------\n");
    i = 0;
    array = calloc(nmemb, size);
    printf("After ft_calloc:\n");
    while (i < nmemb)
    {
        printf("Array element %zu is %d\n", i, array[i]);
        i++;
    }
    free(array);
    return (0);
} */