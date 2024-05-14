/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:06:07 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:06:07 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *s)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (s[i] == ' ' || s[i] >= 9 && s[i] <= 13)
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
        {
            sign = sign * -1;
        }
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');   
        i++;
    }
    result = result * sign;
    return result;
}
/* int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int val;
        val = atoi(argv[1]);
        printf("------------------------------------------------\n");
        printf("Input value = %s\nMy Atoi Value: %d\nReal Atoi Value = %d\n", argv[1], ft_atoi(argv[1]), val);
        char* ans;
        ans = "yes";
        if (ft_atoi(argv[1]) != val)
        {
            ans = "no";
        }
        printf("Is my ATOI value equivalent to the REAL ATOI: %s\n------------------------------------------------\n", ans);
        }
} */