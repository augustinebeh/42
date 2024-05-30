/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 04:23:41 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:17:13 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(strlen(s1) + strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(int argc, char **argv)
{
        char *str;

    if (argc != 3)
        printf("----------ERROR----------");
    else
    {
        str = ft_strjoin(argv[1], argv[2]);
        printf("-------------------------\n");
        printf("The Input of the 1st String is: %s\n", argv[1]);
        printf("The Input of the 2nd String is: %s\n", argv[2]);
        printf("The output of ft_strjoin is   : %s\n", str);
        
        printf("-------------------------\n");
        free(str);
        return (0);    
    }
}

 */