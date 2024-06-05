/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:00 by abeh              #+#    #+#             */
/*   Updated: 2024/06/05 22:41:13 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char			*str;
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = 0;
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		j++;
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	unsigned int	i;
// 	char			find;

// 	find = (char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == find)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == find)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }