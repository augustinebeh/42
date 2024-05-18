/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:23:56 by abeh              #+#    #+#             */
/*   Updated: 2024/05/18 23:28:22 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    int k;
    int len;
    char *str;
    len = ft_strlen(s1);
    i = 0;
    if (!s1 || !set)
    {
        return (0);
    }
    
}

