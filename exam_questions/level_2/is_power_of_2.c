/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:06:00 by abeh              #+#    #+#             */
/*   Updated: 2024/06/11 16:20:41 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = n & (n - 1);
	return (i);
}

int	main(void)
{
	unsigned int	n;
	unsigned int	i;

	n = 15;
	i = is_power_of_2(n);
	printf("output: %d", i);
	return (0);
}
