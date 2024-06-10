/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 04:24:44 by abeh              #+#    #+#             */
/*   Updated: 2024/06/10 14:33:46 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	remove_underscores(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '_')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '_')
			av[1][i + 1] = av[1][i + 1] - 32;
		i++;
	}
   i = 0;
   remove_underscores(av[1]);
   while (av[1][i])
   {
      write(1,&av[1][i],1);
      i++;
   }
   write (1, "\n",1);
   return 0;
}
