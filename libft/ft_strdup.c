/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:09 by abeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:22:57 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*str;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

/* int main(int argc, char **argv)
{
    if (argc == 2)
    {   
        printf("Input   : %s\n", argv[1]);
        char* i;
        i = ft_strdup(argv[1]);
        if (i == NULL)
        {
            printf("Memory allocation failed\n");
            return (1);
        }
        printf("Output  : %s\n", i);
        free(i);
        return (0);
    }
    else
        printf("----------------------ERROR---------------------\n");
} */