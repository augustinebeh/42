/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:12 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:12 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return(i);
}
/*find out why the length of string is way more than it should be if input is: "1//"*/
/* int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error\n");
    }
    else
    {
        printf("------------------------------------------------\n");
        printf("Input value = %s\nLength of the Input: %d\n", argv[1], ft_strlen(argv[1]));
        printf("------------------------------------------------\n");
    }
} */