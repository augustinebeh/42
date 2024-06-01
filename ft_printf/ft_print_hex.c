/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:03:55 by abeh              #+#    #+#             */
/*   Updated: 2024/06/02 04:22:57 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hex(unsigned int num, const char type);
static int	ft_hex_len(unsigned int num);

int	ft_print_hex(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, type);
	return (ft_hex_len(num));
}

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_hex(unsigned int num, const char type)
{
	if (num >= 16)
	{
		ft_hex(num / 16, type);
		ft_hex(num % 16, type);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0');
		else
		{
			if (type == 'x')
				ft_print_char(num - 10 + 'a');
			if (type == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}
