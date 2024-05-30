/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/05/31 01:34:21 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void ft_printf(char *placeholders, ...)
{
    int number_of_arguments = strlen(placeholders);
    
    va_list args;
    va_start(args, placeholders);
    
    for (int i = 0; i < number_of_arguments; i++)
    {
        if (placeholders[i] == 'd' || placeholders[i] == 'i')
        {
            int argument = va_arg(args, int);
            printf("%d\n", argument);
        }
        else if (placeholders[i] == 's')
        {
            char* argument = va_arg(args, char *);
            printf("%s\n", argument);
        }
    }
    va_end(args);
}


int main(void)
{
    ft_printf("ddssd", 1, 2, "ss", "aa", 3);
    return 0;
}