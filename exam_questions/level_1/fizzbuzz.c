/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:08:53 by abeh              #+#    #+#             */
/*   Updated: 2024/06/09 19:23:01 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	put_nbr(int n)
{
	char	c[10];

	c[10] = "0123456789";
	if (n > 9)
		put_nbr(n / 10);
	write(1, &c[n % 10], 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else
		{
			put_nbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
