/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:23:56 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:10:30 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	back_set(char const *s, char const *set);
static size_t	front_set(char const *s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	elefromfront;
	size_t	elefromback;

	elefromfront = front_set(s1, set);
	elefromback = back_set(s1, set);
	len = elefromfront + elefromback + 1;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (elefromfront <= elefromback)
	{
		str[i] = s1[elefromfront];
		elefromfront++;
		i++;
	}
	return (str);
}

static size_t	front_set(char const *s, char const *set)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	while (*s != '\0')
	{
		i = 0;
		while (s[counter] != set[i] && set[i])
			i++;
		if (s[counter] == set[i])
			counter++;
		if (set[i] == '\0')
			return (counter);
	}
	return (counter);
}

static size_t	back_set(char const *s, char const *set)
{
	size_t	i;
	size_t	counter;

	counter = strlen(s) - 1;
	while (*s != '\0')
	{
		i = 0;
		while (s[counter] != set[i] && set[i])
			i++;
		if (s[counter] == set[i])
			counter--;
		else
			return (counter);
	}
	return (counter);
}

/* int main(void)
{
	char	*s;
	char	*set;
	size_t	fs;
	size_t	bs;
	char	*str;

    s = "abcdefabcs";
    set = "bac";
    fs = front_set(s, set);
    bs = back_set(s, set);
    str = ft_strtrim(s, set);
    
    printf("the return (value of front_set: %ld\n", fs));
    printf("the return (value of back_set: %ld\n", bs));
    printf("the return (value of ft_strtrim: %s\n", str));
}
int	main(int argc, char **argv)
{
    char *s = argv[1];
    char *set = argv[2];
    size_t fs = front_set(s, set);
    size_t bs = back_set(s, set);
    char *str = ft_strtrim(s, set);
    
    printf("the return (value of front_set: %ld\n", fs));
    printf("the return (value of back_set: %ld\n", bs));
    printf("the return (value of ft_strtrim: %s\n", str));
} */