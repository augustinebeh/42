/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/29 05:52:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_substring(char *s, char delimiter)
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

static size_t	ft_len_of_next_substring(const char *str, char delimiter)
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
	char	*ss;

	len = ft_len_of_next_substring(&s[element], c);
	ss = (ft_substr(s + element, 0, len));
	return (ss);
}

char	**allocate_strarray(char const *s, char c)
{
	char	**strarray;

	if (s == NULL || *s == '\0')
	{
		strarray = (char **)malloc(sizeof(char *));
		strarray[0] = NULL;
		return (strarray);
	}
	strarray = (char **)malloc((count_substring((char *)s, c) + 1)
			* sizeof(char *));
	if (strarray == NULL)
	{
		return (NULL);
	}
	return (strarray);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strarray;

	strarray = allocate_strarray(s, c);
	if (strarray == NULL)
	{
		return (NULL);
	}
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

// int	main(void)
// {
// 	size_t	i;
// 	char c = '^';
// 	char	*str;
// 	char	**strarray;

// 	str = "^^^1^^2a,^^^^3^^^^--h^^^^";
// 	strarray = ft_split(str, c);
// 	i = 0;
// 	printf("-----------------------------\n");
// 	printf("The Input is: %s\n", str);
// 	printf("The Delimiter is: %c\n", c);
// 	while (i < (count_substring((char *)str, c)))
// 	{
// 		printf("The %ld element in the array is: %s\n", i, strarray[i]);
// 		free(strarray[i]);
// 		i++;
// 	}
// 	printf("-----------------------------\n");
// 	free(strarray);
// 	return (0);
// }
/*
int	main(int argc, char **argv)
{
	char	*str;
	char	**strarray;

	str = argv[1];
	strarray = ft_split(str, argv[2][0]);
	printf("-----------------------------\n");
	printf("The Input is: %s\n", argv[1]);
	printf("The Delimiter is: %s\n", argv[2]);
	printf("Number of substrings: %ld\n", (count_substring((char *)str,
				argv[2][0])));
	while (i < (count_substring((char *)str, argv[2][0])))
	{
		printf("The %d element in the array is: %s\n", i, strarray[i]);
		free(strarray[i]);
		i++;
	}
	free(strarray);
	printf("-----------------------------\n");
	return (0);
}*/
