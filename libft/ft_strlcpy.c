/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:11 by abeh              #+#    #+#             */
/*   Updated: 2024/05/18 18:56:11 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;
    
    i = 0;    
    if (size == 0)
        return 0;
    while (src[i] != '\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}

//----------------------------------------
// Main code to test ft_strlcpy function |
//----------------------------------------

/* int main(int argc, char *argv[])
{
    if (argc != 4)
        printf("ERROR\n");
    else
    {
        char *dst = argv[1];
        char *src = argv[2];
        int size = atoi(argv[3]);
        int srclen = strlen(src);

        printf("Input dst : %s\n", dst);  
        printf("Input src : %s\n", src); 
        printf("Input size: %d\n", size);  
        printf("======================\n");  
        int i = ft_strlcpy(dst, src, size);

        printf("dst after ft_strlcpy : %s\n", dst);
        printf("return of ft_strlcpy : %d\n", i);
        printf("The length of src    : %d\n", srclen);
        if (srclen == i)
        {
            printf("======================\n"); 
            printf("The src was successfully copied & has not been truncated.\n");
            printf("======================\n"); 
        }
        else if (srclen > i)
        {
            printf("======================\n"); 
            printf("**Note** The src has been truncated\n");
            printf("======================\n"); 
        }
        return (0);
    }
} */