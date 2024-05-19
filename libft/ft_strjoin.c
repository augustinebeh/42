/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:23:41 by abeh              #+#    #+#             */
/*   Updated: 2024/05/19 19:48:46 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    unsigned int i;
    unsigned int j;
    
    i = 0;    
    j = 0;
    if (s1 == NULL || s2 == NULL)                   // checks of either s1 or s2 is empty
        return NULL;
    str = malloc(strlen(s1) + strlen(s2) +1);       // allocated memory the length of both s1 and s2
    if (str == NULL)                                // checks for successful memory allocation
        return (NULL);
    while (s1[i])                                   // copies s1 into str
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])                                   // copies s2 into str after s1
    {   
        str[i] = s2[j];
        j++;
        i++;
    }
    str[i] = '\0';                                  // null-terminates the string
    return str;
}

int main(int argc, char **argv)
{
    if (argc != 3)
        printf("----------ERROR----------");
    else
    {
        char *str;
        str = ft_strjoin(argv[1], argv[2]);
        printf("-------------------------\n");
        printf("The Input of the 1st String is: %s\n", argv[1]);
        printf("The Input of the 2nd String is: %s\n", argv[2]);
        printf("The output of ft_strjoin is   : %s\n", str);
        
        printf("-------------------------\n");
        free(str);
        return (0);    
    }
}

