/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:06 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 06:16:34 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == find)
		return ((char *)&s[i]);
	return (NULL);
}

/* int main(int argc, char **argv)
{
    if (argc != 3 || argv[2][1] != '\0')
        printf("----------------------ERROR---------------------\n");
    else
    {   
        char *str;
        char *str2;
        
        str = ft_strchr(argv[1], argv[2][0]);
        str2 = strchr(argv[1], argv[2][0]);
        printf("------------------------------------------------\n");
        printf("Input String : %s\n", argv[1]);
        printf("Char to find : %s\n", argv[2]);
        printf("---------------------\n");
        printf("After ft_strrchr   : %s\n", str);
        printf("After ft_strrchr(address)   : %p\n", str);
        printf("After real strrchr : %s\n", str2);
        printf("After real strrchr(address) : %p\n", str2);
        printf("------------------------------------------------\n");
    }
} */