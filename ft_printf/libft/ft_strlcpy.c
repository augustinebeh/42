/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:11 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 19:09:05 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = strlen(src);
	if (size == 0)
		return (srclen);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
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
        printf("return (of ft_strlcpy) : %d\n", i);
        printf("The length of src    : %d\n", srclen);
        if (srclen == i)
        {
            printf("======================\n"); 
            printf("The src was not truncated.\n");
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