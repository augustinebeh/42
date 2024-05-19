/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:22:57 by abeh              #+#    #+#             */
/*   Updated: 2024/05/19 17:53:38 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// FT_SUBSTR PRODUCES A SUBSTRING FROM A STRING STARTING FROM "START" 
// ONLY TO A MAXIMUM LENGTH "LEN" OF THE SUBSTRING. 

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t j;
    size_t slength;
    
    j = 0;
    slength = strlen(s);
    if (start >= slength)                   // check if the starting index is valid
        return "";                          // return an empty string
    str = malloc(len + 1);                  // allocates memory to str including 1byte space for null terminator
    if (!str)                               // checks in memory allocation is successfull
        return NULL;                        // returns if unsuccessful
    while(j < len && s[start] != '\0')      // while loop ensuring not to go over len & only until the end if s
    {
        str[j] = s[start];                  // copys the value of s[start] into the str[0]
        j++;
        start++;
    }
    str[j] = '\0';                          // adding a null- terminator to the end of the substr
    return (str);           
}

int main(int argc, char **argv)
{
    char *input;
    char *str;
    unsigned int start;
    size_t len;
        
    if (argc != 4)
    {
        printf("-----ERROR-----");
        return(0);
    }
    else
    {
        input = argv[1];
        start = atoi(argv[2]);
        len = atoi(argv[3]);
        str = ft_substr(input, start, len);
        printf("---------------\n");
        printf("Input : %s\n", input);
        printf("Start : %i\n", start);
        printf("Length: %ld\n", len);
        printf("---------------\n");
        printf("Result of ft_substr: %s\n", str);
        return(0);
    }
}

// For debugging purposes
/* int main(void)
{
    char *str;
    unsigned int start;
    size_t len;
    char *result;

    str = "helloworld";
    start = 5;
    len = 5;
    result = ft_substr(str, start, len);
    printf("%s\n", result);
    return (0);
} */
