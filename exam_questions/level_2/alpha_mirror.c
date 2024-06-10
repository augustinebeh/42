/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 06:18:09 by abeh              #+#    #+#             */
/*   Updated: 2024/06/10 06:49:01 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
   if (ac != 2)
   {
      write(1,"\n",1);
      return 0;
   }
   char *str = av[1];
   char *character1 = "abcdefghijklm";
   char *character2 = "zyxwvutsrqpon";
   char *character3 = "ABCDEFGHIJKLMN";
   char *character4 = "ZYXWVUTSRQPON";
   int i = 0;

   while (str[i])
   {
      int j = 0;
      while (character1[j] && character2[j] && character3[j] && character4[j])
      {
         if (str[i] == character1[j])
         {
            str[i] = character2[j];
            break;
         }
         else if (str[i] == character2[j])
         {
            str[i] = character1[j];
            break;
         }
         else if (str[i] == character3[j])
         {
            str[i] = character4[j];
            break;
         }
         else if (str[i] == character4[j])
         {
            str[i] = character3[j];
            break;
         }
         j++;
      }
      write(1,&str[i],1);
      i++;
   }
   write(1,"\n",1);
   return 0;
}

