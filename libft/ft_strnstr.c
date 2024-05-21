/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:17 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:17 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

 char *ft_strnstr(const char *pile, const char *gem, long int n)
 {
    int i;
    const char *p = pile;
    const char *q = gem;
   
    if (n == 0)
        return (NULL);
    if (!*gem)
        return ((char *)pile);
    while (*p && q[i] != '\0')
    {
        if (*p == q[i] && n > 0)
        {
            n--;
            p++;
            i++;
        }
        else if (q[i - 1] == *p)
            i = 0;
        else
            p++;
    }
    while (i > 0)
    {
        p--;
        i--;
    }
    return((char *)p);
 }
 
// Something is wrong with this main code.
// int main(int argc, char **argv)
// {
//     if (argc == 3)
//     {
//         char *result;
//         long int n = strlen(argv[1]) + 1;
//         const char *a = argv[1];
//         const char *b = argv[2];
//         result = ft_strnstr(a, b, n);
//         if (result != NULL)
//         {
//             printf("------------------------------------------------\n");
//             printf("Input String : %s\n", argv[1]);
//             printf("Char to find : %s\n", argv[2]);
//             printf("---------------------\n");
//             printf("Expected Outcome is the rest of the haystack from the first occurence of the needle including the needle");
//             printf("\nOutput: %s\n", result);
//         }
//         else
//         {
//             printf("There is no needle in the haystack\n");
//         }
//     }
//     else 
//         printf("----------------------ERROR---------------------\n");
// }