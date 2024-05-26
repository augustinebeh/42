/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:10 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 05:41:21 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = strlen(dst);
	srclen = strlen(src);
	i = 0;
	if (size <= dstlen)
		return (srclen + size);
	while (src[i] != '\0' && i < size - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen < size)
		dst[dstlen + i] = '\0';
	return (srclen + dstlen);
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
        printf("dst after ft_strlcat : %s\n", dst);
        printf("return (of ft_strlcat : %d\n", i);
        return (0);
    }
} */