/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:22:57 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 04:45:47 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FT_SUBSTR PRODUCES A SUBSTRING FROM A STRING STARTING FROM "START"
// ONLY TO A MAXIMUM LENGTH "LEN" OF THE SUBSTRING.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	size_t	slength;

	j = 0;
	slength = strlen(s);
	if (start >= slength)
		return (ft_strdup(""));
	if (len == 0)
		return (ft_strdup(""));
	str = malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len && start + j < slength)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

/* int	main(int argc, char **argv)
{
	char			*input;
	char			*str;
	unsigned int	start;
	size_t			len;

	if (argc != 4)
	{
		printf("-----ERROR-----");
		return (0);
	}
	else
	{
		input = argv[1];
		start = atoi(argv[2]);
		len = atoi(argv[3]);
		str = ft_substr(input, start, len);
		printf("---------------\n");
		printf("Input : %s\n", input);
		printf("Start : %i\n", start);
		printf("Length: %ld\n", len);
		printf("---------------\n");
		printf("Result of ft_substr: %s\n", str);
		return (0);
	}
}

// For debugging purposes
int	main(void)
{
    char *str;
    unsigned int start;
    size_t len;
    char *result;

    str = "helloworld";
    start = 5;
    len = 3;
    result = ft_substr(str, start, len);
    printf("%s\n", result);
    return (0);
}*/