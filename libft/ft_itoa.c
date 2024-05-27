/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 05:01:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 03:58:06 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int p)
{
	int	i;

	i = 1;
	while (p / 10 != 0)
	{
		p = p / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_positive(int n)
{
	char	*res;
	int		len;

	len = ft_intlen(n);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len-- > 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

static char	*ft_itoa_negative(int n)
{
	char	*res;
	int		len;

	n = n * -1;
	len = ft_intlen(n);
	res = malloc(sizeof(char) * len + 2);
	if (!res)
		return (NULL);
	res[len + 1] = '\0';
	while (len-- > 0)
	{
		res[len + 1] = (n % 10) + '0';
		n = n / 10;
	}
	res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (ft_itoa_negative(n));
	else
		return (ft_itoa_positive(n));
}

/* int	main(int argc, char **argv)
{
	char* hehe;

	hehe = ft_itoa(atoi(argv[1]));
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
} */