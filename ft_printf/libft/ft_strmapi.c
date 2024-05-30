/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:23 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 17:23:43 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	f_function(unsigned int a, char b);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char	f_function(unsigned int a, char b)
{
	return (b - a);
}

int	main(void)
{
	char const	*str;
	char		(*f)(unsigned int, char);
	char		*result;

	str = "I!NRZJ&`W^";
	f = &f_function;
	result = ft_strmapi(str, f);
	if (result == NULL)
	{
		printf("Failed to allocate memory\n");
		return (1);
	}
	printf("%s\n", result);
	free(result);
	return (0);
} */
