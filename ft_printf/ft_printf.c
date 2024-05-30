/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/05/31 05:09:22 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

// use putchar to write all the characters in the first argument of ft_printf function until it finds a '%' sign.
// once it does find the '%' sign, look for the character after the '%' sign to determine which conversion type it is and write that variable argument based on that type.
// also, count the number of % signs that does not have another % sign behind it. and check if the number of argements fit that value. else, produce an error.
// the return value of ft_printf function should return the number of characters output by the function. so use a counter to settle this issue.
//
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.




void ft_printf(char *placeholders, ...)
{
    int number_of_arguments = strlen(placeholders);
    
    va_list args;
    va_start(args, placeholders);
    int j;
    int i;
    
    j = 0;
    i = 0;
    while (strlen(placeholders)> 0)
    {  
        while (placeholders[j] != '%')
        {
            putchar(placeholders[j]);
            j++;
        }
        j++;
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
        i++;
        }
        va_end(args);
}



int main(void)
{
    ft_printf("hello%d%d%s%s%d", 1, 2, "ss", "aa", 3);
    return 0;
}