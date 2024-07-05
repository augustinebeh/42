/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:00 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:03:33 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][1] != '\0')
    {
        printf("----------------------ERROR---------------------\n");
    }
    else
    {
        printf("------------------------------------------------\n");
        printf("Input value = %s\nYes = (1) No = (0): %d\n", argv[1],
		ft_isprint(argv[1][0]));
        printf("------------------------------------------------\n");
    }
} */