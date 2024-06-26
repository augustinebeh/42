/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:49:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/03 21:59:14 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbr(int nb);
static int	ft_intlen(int nb);

int	ft_print_nbr(int nb)
{
	ft_nbr(nb);
	if (nb == -2147483648)
		return (11);
	return (ft_intlen(nb));
}

static void	ft_nbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_print_char('-');
		ft_print_char('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_print_nbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_print_char(nb + 48);
	}
}

static int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
// #include <limits.h>

// int main(void)
// {
// 	int a = ft_printf("BBBBBBBBBBBBBBBBBB: %d\n", INT_MIN);
// 	int b = printf("BBBBBBBBBBBBBBBBBB: %d\n", INT_MIN);

// 	printf("a: %d\n", a);
// 	printf("b: %d\n", b);
// }