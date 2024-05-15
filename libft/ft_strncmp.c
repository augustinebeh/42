/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:16 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:16 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while (0 < n--)
    {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        else if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        else
            i++;
    }
}

// int ft_strncmp(const char *s1, const char *s2, size_t n)
// {
//     int i;
    
//     i = 0;
//     if (!n)
//         return (0);
//     while (s1[i] && s1[i] == s2[i] && i -1 < n)
//         i++;
//     return (s1[i] - s2[i]);
// }

int main(int argc, char **argv)
{
    if (argc != 4)
        printf("----------------------ERROR---------------------\n");
    else
    {   
        int str;
        int str2;
        
        str = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
        str2 = strncmp(argv[1], argv[2], atoi(argv[3]));
        printf("------------------------------------------------\n");
        printf("1st String to Compare: %s\n", argv[1]);
        printf("2nd String to Compare: %s\n", argv[2]);
        printf("Number of Characters to Compare: %s\n", argv[3]);
        printf("---------------------\n");
        printf("After ft_strncmp: %d\n", str);
        printf("After real strncmp: %d\n", str2);
        printf("------------------------------------------------\n");
    }
}