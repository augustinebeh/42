/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:24:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/30 21:11:23 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static size_t	count_ss(char const *s, char c)
{
	int	len;
	int	count;
	int	i;
	int	previous_i;

	len = ft_strlen(s);
	count = 0;
	i = 0;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		previous_i = i;
		while (i < len && s[i] != c)
			i++;
		if (i > previous_i)
			count++;
	}
	return (count);
}

static char	*create_ss(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	init_variables(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	int		s_word;

	init_variables(&i, &j);
	s_word = -1;
	res = ft_calloc((count_ss(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = create_ss(s, s_word, i);
			if (!(res[j]))
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

/* int	main(void)
{
	size_t	i;
	char c = '^';
	char	*str;
	char	**strarray;

	str = "^^^1^^2a,^^^^3^^^^--h^^^^";
	strarray = ft_split(str, c);
	i = 0;
	printf("-----------------------------\n");
	printf("The Input is: %s\n", str);
	printf("The Delimiter is: %c\n", c);
	while (i < (count_ss((char *)str, c)))
	{
		printf("The %ld element in the array is: %s\n", i, strarray[i]);
		free(strarray[i]);
		i++;
	}
	printf("-----------------------------\n");
	free(strarray);
	return (0);
} */

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
