/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:39:37 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    char    *c_src;
    char    *c_dst;
    size_t    i;
    
    if (!dst && !src)
        return (NULL);
    c_src = (char *) src;
    c_dst = (char *) dst;
    i = 0;
    if (c_dst > c_src)
        while (len-- > 0)
            c_dst[len] = c_src[len];
    else
    {
        while (i++ < len)
            c_dst[i] = c_src[i];
    }
    return (dst);
}

/* // PURPOSE OF DOING THIS MEMMOVE IS TO ENSURE THAT IN A CASE
// MEMORY BLOCKS OVERLAP. Example: 
//                 [---- dest ----]
//         [---- src ---]    
//
// PASTING SRC TO THE FRONT OF DEST WILL DESTROY THE 2ND HALF OF DEST
// ANOTHER WAY TO DO IT IS TO COPY FROM THE BACK
//  */
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