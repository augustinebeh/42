/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:06 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:06 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (0);
}

// alternate method to achieve the same result
/*  char *ft_strchr(const char *s, int c)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            j = i;
            k++;
            break;
        }
        i++;
    }
    while (j-- > 0)
        s++;
    if (k > 0)
        return((char *)s);
    else
        return(0);
} */

/* int main(int argc, char **argv)
{
    if (argc != 3 || argv[2][1] != '\0')
        printf("----------------------ERROR---------------------\n");
    else
    {   
        char *str;
        char *str2;
        
        str = ft_strchr(argv[1], argv[2][0]);
        str2 = strchr(argv[1], argv[2][0]);
        printf("------------------------------------------------\n");
        printf("Input String : %s\n", argv[1]);
        printf("Char to find : %s\n", argv[2]);
        printf("---------------------\n");
        printf("After ft_strrchr   : %s\n", str);
        printf("After ft_strrchr(address)   : %p\n", str);
        printf("After real strrchr : %s\n", str2);
        printf("After real strrchr(address) : %p\n", str2);
        printf("------------------------------------------------\n");
    }
} */