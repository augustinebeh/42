/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/06/01 20:49:15 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

#include <unistd.h>
#include <errno.h>
int ft_print_percent();
int ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nb);

int ft_print_percent()
{
	write(1, "%", 1);
	return (1);
}
int ft_print_char(int c)
{
    write(1, &c, 1);
    return(1);
}
int	ft_print_str(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        ft_print_char(*str);
        str++;
        count++;
    }
        return(count);
}
int	ft_print_nbr(int nb) 
{
    int count = 0;
    
    if (nb == -2147483648)
    {
        ft_print_char('-');
        ft_print_char('2');
        count = count + 2;
        nb = 147483648;
    }
	if (nb < 0) {
		ft_print_char('-');
		nb = -nb;
        count++;
	}
	if (nb >= 10) {
		ft_print_nbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
    { 
        ft_print_char(nb + 48);
        count++;
    }
    return(count);
}


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

// • %% Prints a percent sign.
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.

int	ft_type(va_list args, const char type)
{  
    int counter;

    counter = 0;
    if (type == '%')
        counter = counter + ft_print_percent();
    else if (type == 'c')
        counter = counter + ft_print_char(va_arg(args, int));
    else if (type == 's')
        counter = counter + ft_print_str(va_arg(args, char *));
    else if (type == 'd' || type == 'i')
        counter = counter + ft_print_nbr(va_arg(args, int));
    // else if (type == 'p')
    //     counter = counter + ft_print_pointer(va_arg(args, unsigned long long));
    // else if (type == 'u')
    //     counter = counter + ft_print_unsigned(va_arg(args, unsigned int));
    // else if (type == 'x' || type == 'X')
    //     counter = counter + ft_print_hex(va_arg(args, unsigned int), type);
    return (counter);
}
int ft_printf(const char *placeholders,...)
{
    va_list args;
    va_start(args, placeholders);
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (placeholders[i])
    {
        if (placeholders[i] == '%')
        {
            counter = counter + ft_type(args, placeholders[i + 1]);
            i++;
        }
        else
        {
            counter = counter + ft_print_char(placeholders[i]);
        }
        i++;
    }
    va_end(args);
    return (counter);
}

int	main(void)
{
    printf("Hello! The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("--------------------\n");
    ft_printf("Hello! The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n", 'A', 'B', 'C', "Laksa", 3000);
    printf("the number of arguments are: %d\n", n_o_a("Hello! %%%% The first 3 letters are: %c, %c, %c.\nMy favourite food is: %s.\nI have $%d left.\n"));
    int i = 0;
    i = ft_print_nbr(123456789);
    printf("\n the value of i is: %d\n", i);
	return (i);
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
