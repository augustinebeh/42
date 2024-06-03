/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 03:10:48 by abeh              #+#    #+#             */
/*   Updated: 2024/06/03 01:59:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pointer(uintptr_t nb);
static int	ft_pointer_len(uintptr_t nb);

int	ft_print_pointer(unsigned long long pointer)
{
	int	len;

	len = 0;
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = len + write(1, "0x", 2);
	if (pointer == 0)
		len += write(1, "0", 1);
	else
	{
		ft_pointer(pointer);
		len += ft_pointer_len(pointer);
	}
	return (len);
}

static int	ft_pointer_len(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static void	ft_pointer(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_pointer(nb / 16);
		ft_pointer(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_print_char(nb + 48);
		else
			ft_print_char(nb - 10 + 'a');
	}
}
