/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:17 by abeh              #+#    #+#             */
/*   Updated: 2024/05/28 19:23:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*int main(int argc, char **argv)
{
    if (argc == 3)
    {
        char *result;
        long int n = strlen(argv[1]) + 1;
        const char *a = argv[1];
        const char *b = argv[2];
        result = ft_strnstr(a, b, n);
        if (result != NULL)
        {
            printf("---------------------------\n");
            printf("Input String : %s\n", argv[1]);
            printf("Char to find : %s\n", argv[2]);
            printf("---------------------\n");
            printf("\nOutput: %s\n", result);
        }
        else
        {
            printf("There is no needle in the haystack\n");
        }
    }
    else
        printf("----------ERROR----------\n");
} */