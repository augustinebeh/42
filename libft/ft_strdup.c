/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:09 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:09 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strdup(const char *s)
{
    int len;
    char* str;

    len = strlen(s);
    str = (char *) malloc(sizeof(char) * len + 1);
    if (str == NULL)
        return NULL;
    strcpy(str, s);
    return str;
}

/* int main(int argc, char **argv)
{
    if (argc == 2)
    {   
        printf("Input  : %s\n", argv[1]);
        char* i;
        i = ft_strdup(argv[1]);
        if (i == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Input  : %s\n", i);
        free(i);
        return 0;
    }
    else
        printf("----------------------ERROR---------------------\n");
} */