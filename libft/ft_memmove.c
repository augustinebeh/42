/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/17 01:13:04 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// PURPOSE OF DOING THIS MEMMOVE IS TO ENSURE THAT IN A CASE
// MEMORY BLOCKS OVERLAP. Example: 
//                 [---- dest ----]
//         [---- src ---]    
//
// PASTING SRC TO THE FRONT OF DEST WILL DESTROY THE 2ND HALF OF DEST
// ANOTHER WAY TO DO IT IS TO COPY FROM THE BACK
// 
void *ft_memmove(void *dest, const void *src, size_t len)
{
    char *dest_char = (char *)dest; // Cast char* to void dest & throw the value into dest_char
    char *src_char = (char *)src;   // Cast char* to void src & throw the value into src_char
    char *temp = malloc(len);       // Allocate a temporary memory space to temp
    int i = 0;
    while (i < len)
    {
        temp[i] = src_char[i];      // Put the value of src into temp
        i++;
    }
    i = 0;
    while (i < len)
    {
        dest_char[i] = temp[i];     // Put the value of temp into dest
        i++;
    }
    free(temp);                    // Free the temp memory space
    return (dest_char);
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
        return 0;
    }
}*/