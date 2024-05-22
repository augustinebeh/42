/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:04:50 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 22:40:08 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

/* // Change above ft_bzero function\s "\0" into a visible char to test
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("--------ERROR-------\n");
	}
	else
	{
		char *str1 = argv[1];
		size_t number = atol(argv[2]);

		printf("---------------\n");
		printf("Input str : %s\n", str1);
		printf("Input size: %s\n", argv[2]);

		ft_bzero(str1, number);

		printf("\nAfter ft_bzero:\n");
		printf("Output: %s\n", str1);
		printf("---------------\n");
	}
	return (0);
} */