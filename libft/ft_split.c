/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 22:19:15 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_of_substring(char *s, char delimiter)
{
	size_t	count;

	count = 1;
	if (s[0] == delimiter)
		count = 0;
	while (*s)
	{
		if (*s == delimiter && *(s + 1) != delimiter && *(s + 1))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_lenofnextsubstring(const char *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != delimiter && str[i])
		i++;
	return (i);
}

static char	*ft_substring_creater(const char *s, size_t element, char c)
{
	size_t	len;
	size_t	i;
	char	*substring;

	len = ft_lenofnextsubstring(&s[element], c);
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
	{
		free(substring);
		return (NULL);
	}
	i = 0;
	while (s[element] && s[element] != c)
	{
		substring[i] = s[element];
		i++;
		element++;
	}
	substring[i] = '\0';
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strarray;

	strarray = (char **)malloc((ft_number_of_substring((char *)s, c) + 1)
			* sizeof(char *));
	if (strarray == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strarray[j++] = ft_substring_creater(s, i, c);
			i = i + (strlen(strarray[j - 1]));
		}
		else
			i++;
	}
	strarray[j] = NULL;
	return (strarray);
}

/*
int	main(void)
{
	size_t	i;
	char	*str;
	char	**strarray;

	str = "hello!";
	strarray = ft_split(str, ' ');
	i = 0;
	printf("-----------------------------\n");
	printf("The Input is: %s\n", str);
	printf("The Delimiter is: .\n");
	while (i < (ft_number_of_substring((char *)str, '.')))
	{
		printf("The %ld element in the array is: %s\n", i, strarray[i]);
		free(strarray[i]);
		i++;
	}
	printf("-----------------------------\n");
	free(strarray);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**strarray;

	str = argv[1];
	strarray = ft_split(str, argv[2][0]);
	i = 0;
	printf("-----------------------------\n");
	printf("The Input is: %s\n", argv[1]);
	printf("The Delimiter is: %s\n", argv[2]);
	printf("Number of substrings: %ld\n", (ft_number_of_substring((char *)str,
				argv[2][0])));
	while (i < (ft_number_of_substring((char *)str, argv[2][0])))
	{
		printf("The %d element in the array is: %s\n", i, strarray[i]);
		free(strarray[i]);
		i++;
	}
	free(strarray);
	printf("-----------------------------\n");
	return (0);
}*/
