/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:35:04 by abeh              #+#    #+#             */
/*   Updated: 2024/05/27 02:22:40 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}

/* int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("-----------ERROR------------\n");
    }
    else
    {
        size_t len = strlen(argv[1]);    
        char *str = malloc(len + 1);       
        char *str2 = malloc(len + 1);     
        strcpy(str, argv[1]);             
        strcpy(str2, argv[1]);          
        if (str == NULL)                 
        {
            fprintf(stderr, "Memory allocation failed\n");
            return(1);
        }
        printf("----------------------------\n");
        printf("Input string      >> %s\n", argv[1]);

        int t = atoi(argv[3]);             
        char c = argv[2][0];               
        memset(str, c, t);                 
        ft_memset(str2, c, t);             
        printf("After real memset >> %s\n", str); 
        printf("After ft_memset   >> %s\n", str2); 
        printf("--------------------------\n");
        return (0);
    }
} */