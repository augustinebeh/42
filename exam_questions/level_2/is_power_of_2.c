/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:06:00 by abeh              #+#    #+#             */
/*   Updated: 2024/06/11 16:20:41 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
   int i = n & (n-1);
    return i;
}

int main(void)
{
   unsigned int n = 15;
   unsigned int i = is_power_of_2(n);
   printf("output: %d",i);
   return 0;

}
