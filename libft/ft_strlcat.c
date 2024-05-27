/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:10 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 21:14:48 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

//----------------------------------------
// Main code to test ft_strlcat function |
//----------------------------------------

/* int main(int argc, char *argv[])
{
	char	*dst;
	char	*src;
	int		size;
	int		srclen;
	int		i;

    if (argc != 4)
        printf("ERROR\n");
    else
    {
        dst = argv[1];
        src = argv[2];
        size = atoi(argv[3]);
        srclen = strlen(src) + strlen(dst);
        printf("Input dst : %s\n", dst);
        printf("Input src : %s\n", src);
        printf("Input size: %d\n", atoi(argv[3]));
        printf("======================\n");
        i = ft_strlcat(dst, src, size);
        printf("dst after ft_strlcat   : %s\n", dst);
        printf("return (of ft_strlcat) : %d\n", i);
        return (0);
    }
} */