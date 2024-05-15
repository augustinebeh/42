/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:20 by abeh              #+#    #+#             */
/*   Updated: 2024/05/14 22:35:20 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
}

// int main() {
//     char *c = "DhI2wBe3d%";
//     int i = 0;
//     printf("The input is:  %s\nThe output is: ", c);
    
//     while (c[i] != '\0')
//     {
//         printf("%c", ft_toupper(c[i]));
//         i++;
//     }
//     printf("\n");
//     return 0;
// }