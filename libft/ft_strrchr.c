/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:18 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:18 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *ft_strrchr(const char *str, int c)
{
    int i;
    int j;
    int len;

    j = 0;
    i = strlen(str);
    len = strlen(str);
    char *str2 = (char *)malloc(sizeof(char) * (len + 1));
    while (i >= 0)
    {
        if (str[i] == c)
        {
            j = i;
            break;
        }
        i--;
    }
    i = 0;
    while (j <= len)
    {
        str2[i] = str[j];
        j++;
        i++;
    }
    str2[i] = '\0';
    return (str2);
}

/* int main(int argc, char **argv)
{
    if (argc != 3 || argv[2][1] != '\0')
        printf("----------------------ERROR---------------------\n");
    else
    {   
        char *str;
        char *str2;
        
        str = ft_strrchr(argv[1], argv[2][0]);
        str2 = strrchr(argv[1], argv[2][0]);
        printf("------------------------------------------------\n");
        printf("Input String = %s\n", argv[1]);
        printf("Input tofind char: %s\n", argv[2]);
        printf("---------------------\n");
        printf("After ft_strrchr: %s\n", str);
        printf("After real strrchr: %s\n", str2);
        printf("------------------------------------------------\n");
    }
} */