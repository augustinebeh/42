/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:18 by abeh              #+#    #+#             */
/*   Updated: 2024/05/31 16:15:24 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}

/* int main(int argc, char **argv)
{
    if (argc != 3 || argv[2][1] != '\0')
        printf("----------------------ERROR---------------------\n");
    else
    {   
        char *str;
        char *str2;
        
        str = ft_strrchr(argv[1], argv[2][0]);
        str2 = strrchr(argv[1], argv[2][0]);
        printf("------------------------------------------------\n");
        printf("Input String : %s\n", argv[1]);
        printf("Char to find : %s\n", argv[2]);
        printf("---------------------\n");
        printf("After ft_strrchr  : %s\n", str);
        printf("After ft_strrchr(address)  : %p\n", str);
        printf("After real strrchr: %s\n", str2);
        printf("After real strrchr(address): %p\n", str2);
        printf("------------------------------------------------\n");
    }
} */