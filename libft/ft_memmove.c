/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 21:23:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	i = 0;
	if (temp_dst > temp_src)
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	else
	{
		while (i++ < len)
			temp_dst[i] = temp_src[i];
	}
	return (dst);
}

/* int main(int argc, char **argv)
{
    if (argc != 4)
        printf("----------------------ERROR---------------------\n");
    else
    {
        size_t len = strlen(argv[1]);
        char *d = malloc(sizeof(char) * (len + 1));
        if (!d)
        {
            fprintf(stderr, "Memory allocation failed for d\n");
            return (1);
        }

        char *s = malloc(sizeof(char) * (len + 1));
        if (!s)
        {
            fprintf(stderr, "Memory allocation failed for s\n");
            return (1);
        }
        strcpy(d, argv[1]);
        strcpy(s, argv[2]);

        char* y = (char*)ft_memmove(d, s, atoi(argv[3]));
        printf("----------------------------------------\n");
        printf("Input               : %s\n", argv[1]);
        printf("----------------------------------------\n");
        printf("Output(ft_memmove)   : %s\n", y);

        char* x = (char*)memmove(d, s, atoi(argv[3]));
        printf("Output(memmove)      : %s\n", x);
        printf("----------------------------------------\n");
        free(d);
        free(s);
        return (0);
    }
}*/