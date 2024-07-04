/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:01 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 21:20:12 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	uc;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int main(int argc, char **argv)
{
    if (argc != 4)
        printf("-----------------ErRoR----------------\n");
    else
    {
        char* y;
        char* z;

        printf("----------------------------------------\n");
        printf("Input            : %s\n", argv[1]);
        printf("----------------------------------------\n");

        y = (char*)memchr(argv[1], (argv[2][0]), atoi(argv[3]));
        printf("Output(memchr)   : %s\n", y);

        z = (char*)ft_memchr(argv[1], (argv[2][0]), atoi(argv[3]));
        printf("Output(ft_memchr): %s\n", y);

        return(0);
    }
} */