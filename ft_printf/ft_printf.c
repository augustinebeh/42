/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/06/01 06:39:18 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// counts the number of '%' characters in the string that is followed by a valid
// character in order determine the number of variables

void	ft_putnbr(int n);
void	ft_putchar(char c);

static int	n_o_a(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
				|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
				|| str[i + 1] == 'x' || str[i + 1] == 'X')
				count++;
			else if (str[i + 1] == '%')
				i++;
			else
			{
				printf("Error: unknown conversion type\n");
				return (0);
			}
		}
		i++;
	}
	return (count);
}

void ft_printf(char *placeholders,...)
{
    va_list args;
    va_start(args, placeholders);
    int i = 0;
    int k;

    while (placeholders[i])
    {
        if (placeholders[i] == '%' && placeholders[i+1] == '%')
        {
            putchar('%');
            i = i + 2;
        }
        if (placeholders[i] == '%' && placeholders[i+1] != '%')
        {
            i++;
            if (placeholders[i] == '%')
            {
                putchar('%');
                i++;
            }
            else if (placeholders[i] == 'c')
            {
                char argument = va_arg(args, int);
                putchar(argument);
            }
            else if (placeholders[i] == 'd')
            {
                int argument = va_arg(args, int);
                ft_putnbr(argument);
            }
            else if (placeholders[i] == 's')
            {
                char* argument = va_arg(args, char *);
                k = 0;
                while (argument[k])
                    putchar(argument[k++]);
            }
           
        }
        else
        {
            putchar(placeholders[i]);
        }
        i++;
    }
    va_end(args);
}
        

int	main(void)
{
    printf("Hello! %%%%%% The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("--------------------\n");
    ft_printf("Hello! %%%%%% The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("the number of arguments are: %d\n", n_o_a("Hello! %%%% The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n"));

	return (0);
}

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
	if (nb < 0) {
		putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) putchar(nb + 48);
}
// use putchar to write all the characters in the first argument of ft_printf
//function until it finds a '%' sign.
// once it does find the '%' sign look for the character after the '%' sign to
//determine which conversion type it is and write that variable argument based
//on that type.
// also, count the number of % signs that does not have another
// % sign behind it. and check if the number of argements fit that value. else,
// produce an error.
// the return value of ft_printf function should return the number of characters
// output by the function. so use a counter to settle this issue.
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
