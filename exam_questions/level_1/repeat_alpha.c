/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:54:32 by abeh              #+#    #+#             */
/*   Updated: 2024/06/10 15:05:57 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_index(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 1;
	else
		return (1);
	return (c);
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
		while (j < ft_index(av[1][i]))
		{
			write(1, &av[1][i], 1);
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
