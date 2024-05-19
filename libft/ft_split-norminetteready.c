/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split-norminetteready.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/20 02:37:26 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Counts the number of delimiter
size_t	ft_delimiter_counter(char *s, char delimiter)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == delimiter)
			count++;
		s++;
	}
	return (count);
}

size_t	ft_lenofnextsubstring(const char *str, char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] != delimiter && str[i])
		i++;
	return (i);
}

char	*ft_substring_creater(const char *s, size_t element, char c)
{
	size_t	len;
	size_t	i;
	char	*substring;

	len = ft_lenofnextsubstring(&s[element], c);
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
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

	strarray = (char **)malloc(((ft_delimiter_counter((char *)s, c) + 1))
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

/*int	main(void)
{
	size_t	i;
	char	*str;
	char	**strarray;

	str = "aa.bb.cc.dd.ee";
	strarray = ft_split(str, '.');
	i = 0;
	printf("-----------------------------\n");
	while (i < (ft_delimiter_counter((char *)str, '.') + 1))
	{
		printf("The %ld element in the array is: %s\n", i, strarray[i]);
		i++;
	}
	printf("-----------------------------\n");
	free(strarray);
	return (0);
}

int	main(int argc, char **argv)
{
    int i;
	char	*str;
    char **strarray;

    str = argv[1];
    strarray = ft_split(str, argv[2][0]);
    i = 0;
    printf("-----------------------------\n");
    while (i < (ft_delimiter_counter((char *)str, argv[2][0]) + 1))
    {
        printf("The %d element in the array is: %s\n", i, strarray[i]);
        i++;
    }
    printf("-----------------------------\n");
    return(0);
}
 */
