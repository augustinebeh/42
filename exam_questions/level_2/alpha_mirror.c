/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:18:09 by abeh              #+#    #+#             */
/*   Updated: 2024/06/10 06:49:01 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*character1;
	char	*character2;
	char	*character3;
	char	*character4;
	int		i;
	int		j;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	character1 = "abcdefghijklm";
	character2 = "zyxwvutsrqpon";
	character3 = "ABCDEFGHIJKLMN";
	character4 = "ZYXWVUTSRQPON";
	i = 0;
	while (str[i])
	{
		j = 0;
		while (character1[j] && character2[j] && character3[j] && character4[j])
		{
			if (str[i] == character1[j])
			{
				str[i] = character2[j];
				break ;
			}
			else if (str[i] == character2[j])
			{
				str[i] = character1[j];
				break ;
			}
			else if (str[i] == character3[j])
			{
				str[i] = character4[j];
				break ;
			}
			else if (str[i] == character4[j])
			{
				str[i] = character3[j];
				break ;
			}
			j++;
		}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
