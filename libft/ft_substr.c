/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:22:57 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 05:32:57 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// FT_SUBSTR PRODUCES A SUBSTRING FROM A STRING STARTING FROM "START"
// ONLY TO A MAXIMUM LENGTH "LEN" OF THE SUBSTRING.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
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