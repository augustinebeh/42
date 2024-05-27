/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:34 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 16:33:05 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void	f_function(unsigned int index, char *c)
{
	*c = *c - index;
}

int	main(void)
{
	char str[] = "Hfnos1&^w{vo-";
	void (*f)(unsigned int, char *);
    
	f = f_function;
	ft_striteri(str, f);
	printf("%s\n", str);
	return (0);
} */