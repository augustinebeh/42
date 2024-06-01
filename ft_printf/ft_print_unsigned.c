/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:27:37 by abeh              #+#    #+#             */
/*   Updated: 2024/06/02 02:14:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_unsigned(unsigned int nb);
static int ft_unsigned_len(unsigned int nb);

int ft_print_unsigned(unsigned int nb)
{
    ft_unsigned(nb);
    return(ft_unsigned_len(nb));
}
static void	ft_unsigned(unsigned int nb) 
{
	if (nb >= 10) 
    {
		ft_print_unsigned(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
    { 
        ft_print_char(nb + 48);
    }
}

static int ft_unsigned_len(unsigned int nb)
{
    int len;
    
    len = 0;
    if (nb == 0)
        return (1);
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}