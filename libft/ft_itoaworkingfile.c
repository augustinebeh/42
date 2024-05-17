/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaworkingfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:22:22 by abeh              #+#    #+#             */
/*   Updated: 2024/05/17 15:29:42 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_intlen(int p)
{
    int i = 0;

    while (p != 0)
    {
        p = p / 10;
        i++;
    }

    return (i);
}
// main code to test ft_intlen
/*  int main(void)
{
    int y = intlen(12123123);
    printf("value of y = %d\n", y);
    return 0;
}  */

char *ft_itoa(int n)
{
    char *result1;
    int result;
    int j;
    int len;
    int len2;

    j = 0;
    result = n;
    if (result < 0)            // Convert the value of result from a "-ve" to a "+ve"
    {
        result = result * -1;
        j = 1;                 // If input is "-ve", j=1 | if input is "+ve", j=0
    }
    len = ft_intlen(result);
    len2 = len;           
    result1 = malloc(sizeof(char) * len + 1);
    if (result1 == NULL)       // Check if allocation failed
        return NULL;           // Return NULL
    while (len + 1 + j > 0)    // Add j to this equation to increment result1 further back by 1
    {
        result1++;
        len--;
    }
    *result1 = '\0';
    result1--;
    while (result != 0)
    {
        *result1 = (result % 10) + '0';
        result = result / 10;
        if (len2 - 1 + j > 0)
        {
            result1--;
            len2--;
        }
    }
    if (j == 1)                //If input is negative, add "-"
        *result1 = '-';
    return (result1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("-----ERROR-----\n");
    }
    else
    {
        int c = atoi(argv[1]);

        char *hehe = ft_itoa(c);
        printf("Input is: %s\n", argv[1]);
        printf("Output is: %s\n", hehe);
    }
    return (0);
}

/* int main(void)
{
    int c = atoi("123");

    char *hehe = ft_itoa(c);
    printf("The input is: %s\n", "123");
    printf("The output is: %s\n", hehe);
    return(0);
} */