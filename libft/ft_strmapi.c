/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:23 by abeh              #+#    #+#             */
/*   Updated: 2024/05/22 00:17:03 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char f_impl(unsigned int a, char b)
{
    return (b + a);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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



int main(void)
{
    char const *str = "aaaaaaaaaaa";
    char (*f)(unsigned int, char) = &f_impl;
    char *result = ft_strmapi(str, f);

    if (result == NULL)
    {
        printf("Failed to allocate memory\n");
        return (1);
    }

    printf("%s\n", result);
    free(result);

    return (0);
}