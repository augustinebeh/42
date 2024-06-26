/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:03 by abeh              #+#    #+#             */
/*   Updated: 2024/06/04 00:24:59 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

//main file for manual testcases. argc based on number of input variables
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
        ft_memcpy(d, s, atoi(argv[3]));
        printf("----------------------------------------\n");
        printf("Input               : %s\n", argv[1]);
        printf("----------------------------------------\n");
        printf("Output(ft_memcpy)   : %s\n", d);

        memcpy(d, s, atoi(argv[3]));
        printf("Output(memcpy)      : %s\n", d);
        printf("----------------------------------------\n");
        free(d);
        free(s);
        return (0);
    }
} */
