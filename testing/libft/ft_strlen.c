/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:12 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:41:44 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error\n");
    }
    else
    {
        printf("------------------------------------------------\n");
        printf("Input value = %s\nLength of the Input: %d\n", argv[1],
		ft_strlen(argv[1]));
", argv[1], ft_strlen(argv[1]));
_strlen(argv[1]));
_strlen(argv[1]));
ft_strlen(argv[1]));
        printf("------------------------------------------------\n");
    }
} */