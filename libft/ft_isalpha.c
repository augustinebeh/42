/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:34:54 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:34:54 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isalpha(int c)
{
    if ((c >= 'a' && c<= 'z') 
    || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

/* int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][1] != '\0')
    {
        printf("----------------------ERROR---------------------\n");
    }
    else
    {
        printf("------------------------------------------------\n");
        printf("Input value = %s\nYes = (1) No = (0): %d\n", argv[1], ft_isalpha(argv[1][0]));
        printf("------------------------------------------------\n");
    }
} */