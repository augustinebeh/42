/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/20 02:33:27 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Prototype char **ft_split(char const *s, char c);
Turn in files -
Parameters s: The string to be split.
c: The delimiter character.
Return value The array of new strings resulting from the split.
NULL if the allocation fails.
External functs. malloc, free
Description Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
// Output the length of the start of the string to the first occurence of the delimiter
size_t	ft_lenofnextsubstring(const char *str, char delimiter)
{
	size_t	i;
	i = 0;
	while (str[i] != delimiter && str[i])
		i++;
	return (i);
}
// Creates the next substring from delimiter to delimiter
char	*ft_substring_creater(const char *s, size_t element, char c)
{
	size_t	len;
	size_t	i;

	len = ft_lenofnextsubstring(&s[element], c);        // find the length of the next substring
	char	*substring;
	substring = malloc((len + 1) * sizeof(char)); // allocate memory based on the length of the individual string + 1 for the null-terminator
	if (!substring)
		return (NULL);
	i = 0;
	while (s[element] && s[element] != c) // iterate the next substring to the array in the array of strings
	{
		substring[i] = s[element];
		i++;
		element++;
    }
	substring[i] = '\0'; // adds a null-terminator to the end of the substring
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strarray;

	strarray = (char **)malloc(((ft_delimiter_counter((char *)s, c) + 1)) * sizeof(char *)); // allocates memory for a 2d array
	if (strarray == NULL)
		return NULL;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strarray[j++] = ft_substring_creater(s, i, c); // iterates to the next string in the array of strings
			i = i + (strlen(strarray[j - 1]));
		}
		else
			i++; // skips the delimiter
	}
	strarray[j] = NULL;
	return (strarray);
}

int	main(void)
{
	int	i;
	char	*str = "aa.bb.cc.dd.ee";

	char	**strarray;
	strarray = ft_split(str, '.');
	i = 0;
	printf("-----------------------------\n");
	while (i < (ft_delimiter_counter((char *)str, '.') + 1))
	{
		printf("The %d element in the array is: %s\n", i, strarray[i]);
		i++;
	}
	printf("-----------------------------\n");
	free(strarray);
	return (0);
}

/* int main(int argc, char **argv)
{
    int i;
    char *str = argv[1];

    char **strarray;
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
