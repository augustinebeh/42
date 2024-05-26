/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:01:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:03:39 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p = p / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_positive(int n)
{
	char	*res;
	int		len;
	int		len2;

	len = ft_intlen(n);
	len2 = len;
	res = malloc(sizeof(char) * len + 1);
	while (len-- + 1 > 0)
		res++;
	*res = '\0';
	res--;
	while (n != 0)
	{
		*res = (n % 10) + '0';
		n = n / 10;
		if (len2 - 1 > 0)
		{
			res--;
			len2--;
		}
	}
	return (res);
}

char	*ft_itoa_negative(int n)
{
	char	*res;
	int		len;

	n = n * -1;
	len = ft_intlen(n);
	res = malloc(sizeof(char) * len + 1);
	while (len-- + 2 > 0)
		res++;
	*res = '\0';
	res--;
	len = len + 3 + ft_intlen(n);
	while (n != 0)
	{
		*res = (n % 10) + '0';
		n = n / 10;
		if (len-- > 0)
			res--;
	}
	*res = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_negative(n));
	else
		return (ft_itoa_positive(n));
}

/* int	main(int argc, char **argv)
{
	char*hehe;

	hehe = ft_itoa(argv[1]);
	if (argc != 2)
	{
		printf("----------------------ERROR---------------------\n");
	}
	else
	{
		printf("The input is: %s\n", argv[1]);
		printf("The output is: %s\n", hehe);
	}
	return (0);
}
 */