/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/07/03 06:00:31 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_type(va_list args, const char type, int *error);
// static int	n_o_a(const char *str);

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		i;
	int		counter;
	int		error;

	va_start(args, placeholders);
	i = 0;
	error = 0;
	counter = 0;
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			counter = counter + ft_type(args, placeholders[i + 1], &error);
			i++;
		}
		else
			counter = counter + ft_print_char(placeholders[i]);
		i++;
	}
	va_end(args);
	if (error == -1)
		return (error);
	return (counter);
}

static int	ft_type(va_list args, const char type, int *error)
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
	else
		*error = -1;
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

// int	main(void)
// {
// 	int	i;
// 	int	j;
// 	int x = 123;
// 	char *str;

// 	str = NULL;
// 	printf("\n===============================================\n");
// 	printf("              PRINTF   OUTPUTS");
// 	printf("\n===============================================\n");
// 	i = printf("integers || %d, %d, %d || %c, %c, %c || characters\n", 1, 2, 3,
// 			'A', 'B', 'C');
// 	i = i + printf(" strings || %s  || %u || unsigned ints\n", str,
// 			4242424);
// 	i = i + printf("     hex || %x || %X || HEX  \n", 42424242, 97521595);
// 	i = i + printf(" The pointer address of printf ||\n");
// 	i = i + printf("                          NULL || %p\n", NULL);
// 	i = i + printf("                 Address of x  ||%p\n", (void *)&x);
// 	i += printf("identical conversions: %c%s%d%i%p%u%x%X\n",'a', "bb", 1, INT_MIN, NULL, 2222222222, 123, 321);
// 	printf("  The return (value of printf is : %d \n", i);


// 	ft_printf("\n===============================================\n");
// 	ft_printf("             FT_PRINTF   OUTPUTS");
// 	ft_printf("\n===============================================\n");
// 	j = ft_printf("integers || %d, %d, %d || %c, %c, %c || characters\n", 1, 2,
// 			3, 'A', 'B', 'C');
// 	j = j + ft_printf(" strings || %s  || %u || unsigned ints\n", str,
// 			4242424);
// 	j = j + ft_printf("     hex || %x || %X || HEX  \n", 42424242, 97521595);
// 	j = j + ft_printf(" The pointer address of printf ||\n");
// 	j = j + ft_printf("                          NULL || %p\n", NULL);
// 	j = j + ft_printf("                  Address of x ||%p\n", (void *)&x);
// 	j += ft_printf("identical conversions: %c%s%d%i%p%u%x%X\n",'a', "bb", 1, INT_MIN, NULL, 2222222222, 123, 321);
// 	ft_printf("  The return (value of printf is : %d \n", j);
// 	return (0);
// }
