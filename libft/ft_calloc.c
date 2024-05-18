/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:34:50 by abeh              #+#    #+#             */
/*   Updated: 2024/05/19 02:28:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
// remove this memset function for submission.
void		*ft_memset(void *ptr, int c, size_t len)
{
    size_t		i;                  // to match with size_t len
    i = 0;                          
    while (i < len)
    {
        ((char *)ptr)[i] = c;       // cast char* to void
        i++;
    }
    return(ptr);
}
// BASICALLY, CALLOC IS MALLOC BUT MEMSETS THE ALLOCATED MEMORY TO "0"
 void *ft_calloc(size_t nmemb, size_t size)
 {
    void *ptr;
    size_t i;
    if (nmemb == 0 || size == 0)        //returns NULL if either variable is 0
        return (NULL);
    ptr = malloc(nmemb * size);         //allocates memory for nmemb * size
    if (ptr == NULL)                    //returns NULL if malloc allocation fails
        return (NULL);
    ft_memset(ptr, 0, nmemb * size);    //sets all bytes to 0
    return(ptr);
}

int main()
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
    return 0;
}