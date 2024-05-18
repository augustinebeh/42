/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:10 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// STRLCAT        -  Concatenates src behind dst. The concatenation should not exceed the input size(3rd variable).
// RETURN VALUES  -
//                  If size is empty, return => length of src
//                  If size is larger than the length of dst, return => length of src + length of dst 
//                  If size is smaller than the length of dst, return => length of src + size

size_t ft_strlcat(char *dst, const char *src, size_t size) 
{
    size_t dstlen = strlen(dst);
    size_t srclen = strlen(src);
    size_t i = 0;
    size_t j = 0;

    if (size <= dstlen)
        return (srclen + size); 
    
    while (src[i] != '\0' && j < size - dstlen - 1)
    {
        dst[dstlen +i] = src[i];
        i++;
        j++;
    }
    dst[dstlen + i] = '\0';
    return (srclen + dstlen);
}
//----------------------------------------
// Main code to test ft_strlcat function |
//----------------------------------------

int main(int argc, char *argv[])
{
    if (argc != 4)
        printf("ERROR\n");
    else
    {
        char *dst = argv[1];
        char *src = argv[2];
        int size = atoi(argv[3]);
        int srclen = strlen(src) + strlen(dst);

        printf("Input dst : %s\n", dst);
        printf("Input src : %s\n", src);
        printf("Input size: %d\n", atoi(argv[3]));
        printf("======================\n");
        int i = ft_strlcat(dst, src, size);

        printf("dst after ft_strlcat : %s\n", dst);
        printf("return of ft_strlcat : %d\n", i);
        return (0);
    }
}