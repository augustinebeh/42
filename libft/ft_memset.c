/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/16 18:10:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

/* int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("----------------------ERROR---------------------\n");
    }
    else
    {
        size_t len = strlen(argv[1]);      //find the length of argv[1]
        char *str = malloc(len + 1);       //allocate a memory for str based on the length of str + 1 is ofr the null byte
        char *str2 = malloc(len + 1);      //allocate a memory for str based on the length of str + 1 is ofr the null byte
        strcpy(str, argv[1]);              //copy arrgv[1] into str
        strcpy(str2, argv[1]);              //copy arrgv[1] into str2
        if (str == NULL)                   //ensuring that memory is being allocated for str
        {
            fprintf(stderr, "Memory allocation failed\n");
            return(1);
        }
        printf("------------------------------------------------\n");
        printf("Input string      >> %s\n", argv[1]);

        int t = atoi(argv[3]);             //convert argv[3] into integer to use in memset function
        char c = argv[2][0];               //unnecessary -- only to simplify the variable for memset function
        memset(str, c, t);                 //applying built-in memset to the str
        ft_memset(str2, c, t);             //applying my created memset to the str
        printf("After real memset >> %s\n", str); //prints the output of the built-in memset function
        printf("After ft_memset   >> %s\n", str2); //prints the output of my created memset function
        printf("------------------------------------------------\n");
        return 0;
    }
} */