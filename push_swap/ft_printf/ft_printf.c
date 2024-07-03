/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:09:08 by abeh              #+#    #+#             */
/*   Updated: 2024/07/04 07:24:56 by abeh             ###   ########.fr       */
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
