/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:48 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 15:54:32 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main(void)
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd(' ', 1);
    ft_putchar_fd('W', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd('r', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('d', 1);
    ft_putchar_fd('!', 1);
    printf("\n");
    return (0);
} */