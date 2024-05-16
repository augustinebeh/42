/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:02 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:02 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 1;
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;
    if (n == 0)
    {
        return (0);
    }
    while (i < n)
    {
        if (*p1 != *p2)
            return (*p1 - *p2);
        else
        {
            p1++;
            p2++;
        }
        i++;
    }
    return (*p1 - *p2);
}

// main file for manual testcases. argc based on number of input variables
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
            return 1;
        }

        char *s = malloc(sizeof(char) * (len + 1));
        if (!s)
        {
            fprintf(stderr, "Memory allocation failed for s\n");
            return 1;
        }
        strcpy(d, argv[1]);
        strcpy(s, argv[2]);

        int y = ft_memcmp(d, s, atoi(argv[3]));
        printf("----------------------------------------\n");
        printf("Input               : %s\n", argv[1]);
        printf("----------------------------------------\n");
        printf("Output(ft_memcmp)   : %d\n", y);

        int x = memcmp(d, s, atoi(argv[3]));
        printf("Output(memcmp)      : %d\n", x);
        printf("----------------------------------------\n");
        free(d);
        free(s);
        return 0;
    }
} */

/* int main(void)
{
    size_t len = strlen("hello");
    char *d = malloc(sizeof(char) * (len + 1));
    if (!d)
    {
        fprintf(stderr, "Memory allocation failed for d\n");
        return 1;
    }

    char *s = malloc(sizeof(char) * (len + 1));
    if (!s)
    {
        fprintf(stderr, "Memory allocation failed for s\n");
        return 1;
    }
    strcpy(d, "hello");
    strcpy(s, "healo");

    int y = ft_memcmp(d, s, 2);
    printf("----------------------------------------\n");
    printf("Input               : %s\n", "HelloMyLove");
    printf("----------------------------------------\n");
    printf("Output(ft_memcmp)   : %d\n", y);

    int x = memcmp(d, s, 2);
    printf("Output(memcmp)      : %d\n", x);
    printf("----------------------------------------\n");
    free(d);
    free(s);
    return 0;
} */
