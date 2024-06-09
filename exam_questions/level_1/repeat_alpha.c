/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:03:53 by abeh              #+#    #+#             */
/*   Updated: 2024/06/09 22:19:07 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	convert_alpha_to_i(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		j = 0;
		while ((convert_alpha_to_i(av[1][i])) > j)
		{
			write(1, &av[1][i], 1);
			j++;
		}
		i++;
	}
}
