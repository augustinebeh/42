/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/06/01 13:11:16 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_printchar(int c);

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

int ft_printf(const char *placeholders,...)
{
    va_list args;
    va_start(args, placeholders);
    int i = 0;
    int k;
    int counter;

    while (placeholders[i])
    {
        if (placeholders[i] == '%')
        {
            i++;
            counter++;
            if (placeholders[i] == '%')
            {
                putchar('%');
                i++;
                counter++;
            }
            else if (placeholders[i] == 'c')
            {
                char argument = va_arg(args, int);
                counter = counter + ft_printchar(argument);
            }
            else if (placeholders[i] == 'd'|| placeholders[i] == 'i')
            {
                int argument = va_arg(args, int);
                counter = counter + ft_putnbr(argument);
            }
            else if (placeholders[i] == 's')
            {
                char* argument = va_arg(args, char *);
                k = 0;
                while (argument[k])
                    putchar(argument[k++]);
                    counter ++;
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
    printf("Hello! The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("--------------------\n");
    ft_printf("Hello! The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("the number of arguments are: %d\n", n_o_a("Hello! %%%% The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n"));

	return (0);
}

int ft_printchar(int c)
{
    write(1, &c, 1);
    return 1;
}

int	ft_putnbr(int nb) 
{
    int count = 0;
    if (nb == -2147483648)
    {
        ft_printchar('-');
        ft_printchar('2');
        count = 2;
        nb = 147483648;
    }
	if (nb < 0) {
		putchar('-');
		nb = -nb;
        count++;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
    { 
        putchar(nb + 48);
        count++;
    }
    return(count);
}

int	ft_putstr(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        ft_printchar(*str);
        str++;
        count++;
    }
        return(count);
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
