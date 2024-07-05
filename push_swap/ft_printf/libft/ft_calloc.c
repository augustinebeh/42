/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:34:50 by abeh              #+#    #+#             */
/*   Updated: 2024/06/02 19:18:50 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	res = (void *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
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