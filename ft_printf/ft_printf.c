/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/06/02 04:19:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list args, const char type);
// static int	n_o_a(const char *str);

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, placeholders);
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
			counter = counter + ft_print_char(placeholders[i]);
		i++;
	}
	va_end(args);
	return (counter);
}

static int	ft_type(va_list args, const char type)
{
	int	counter;

	counter = 0;
	if (type == '%')
		counter = counter + ft_print_percent();
	else if (type == 'c')
		counter = counter + ft_print_char(va_arg(args, int));
	else if (type == 's')
		counter = counter + ft_print_str(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		counter = counter + ft_print_nbr(va_arg(args, int));
	else if (type == 'p')
		counter = counter + ft_print_pointer(va_arg(args, unsigned long long));
	else if (type == 'u')
		counter = counter + ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		counter = counter + ft_print_hex(va_arg(args, unsigned int), type);
	return (counter);
}
// static int	n_o_a(const char *str)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '%')
// 		{
// 			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
// 				|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
// 				|| str[i + 1] == 'x' || str[i + 1] == 'X')
// 				count++;
// 			else if (str[i + 1] == '%')
// 				i++;
// 			else
// 			{
// 				printf("Error: unknown conversion type\n");
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return (count);
// }

/* int	main(void)
{
    int i;
    int j;
    int k;
    printf("\n===============================================\n");
    i = printf("integers || %d, %d, %d || %c, %c, %c || characters\n strings ||
		%s || %u || unsigned ints\n     hex || %x || %X || HEX\n",
        1, 2, 3, 'A', 'B', 'C', "strings", 1234567, 123456789, 98765432);
        printf("    The return (value of printf is: %d\n", i));
        printf("   The pointer address of printf is: %p\n", 333);

    ft_printf("\n===============================================\n");
    j = ft_printf("integers || %d, %d, %d || %c, %c, %c || characters\n strings
		|| %s || %u || unsigned ints\n     hex || %x || %X || HEX\n",
        1, 2, 3, 'A', 'B', 'C', "strings", 1234567, 123456789, 98765432);
        ft_printf("    The return (value of ft_printf is: %d\n", j));
        ft_printf("   The pointer address of printf is: %p\n", 333);

    printf("\n===============================================\n");
    printf("The number of arguments are: %d\n",
        n_o_a("integers || %d, %d, %d || %c, %c, %c || characters\n strings ||
		%s || %u || unsigned ints\n     hex || %x || %X || HEX\n"));
    printf("===============================================\n");
    printf("The value of int_max is: ");
    k = ft_print_nbr(2147483647);
    printf("\nThe length of the above is: %d\n", k);
    printf("===============================================\n");

	return (0);
} */
