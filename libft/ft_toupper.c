/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:20 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:20 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char* ft_toupper(char* c)
{
    int i;
    
    i = 0;
    while (c[i] != '\0')
    {
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            c[i] = c[i] - 32;
        }
        i++;
    }
    return c;
}

/* int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error\n");
    }
    else
    {
        char* result;

        result = ft_toupper(argv[1]);
        printf("Input is: %s\n", argv[1]);
        printf("------------------------------------------------\n");
        printf("Uppercase equivalent of %s is %s\n", (argv[1]), result);
        printf("------------------------------------------------\n");
        return (0);
    }
} */