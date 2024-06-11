/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:13:31 by abeh              #+#    #+#             */
/*   Updated: 2024/06/11 03:17:32 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
   int i;
   int sign;
   int num;
   int result;
   i = 0;
   sign = 1;
   num = 0;
   result = 0;
   while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
      i++;
   if (s[i] == '-' || s[i] == '+')
   {
      if (s[i] == '-')
         sign = -1;
      i++;
   }
   while (s[i] >= '0' && s[i] <= '9')
   {
      num = s[i] - '0';
      result = result * 10 + num;
      i++;
   }
   return (result * sign);
}
