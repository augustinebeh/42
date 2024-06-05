/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/05 14:46:36 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_str(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_line(char *str);

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // malloc the first "BUFFER_SIZE" of the string
	if (!buff)
		return (NULL);
	bytes = 1; // bytes useed as a checker.
	while (!ft_strchr(str, '\n') && bytes != 0) // while cannot find '\n' in str,
	{
		bytes = read(fd, buff, BUFFER_SIZE); // if cannot read, return -1, will free everything
		if (bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[bytes] = '\0'; // null terminate the str
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next_str(str);
	return (line);
}


char	*ft_line(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
	{
		free(str);
		return (NULL);
	}
	tab[i] = '\0';
	while (i > 0)
	{
		i--;
		tab[i] = str[i];
	}
	if (str[i] == '\n')
	{
		tab[i] = str[i];
		i--;
	}
	return (tab);
}

char	*ft_next_str(char *str) // find the balance portion of the string and store it in a new malloc.
{
	int		i;
	int		j;
	char	*woo;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i]) //if the string after iterating through non '\0' n '\n' is NULL, free string and return null
	{
		free(str);
		return (NULL);
	}
	woo = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1)); //malloc a space based on length of string minus all the characters until the null byte
	if (!woo) // guard
	{
		free(str);
		return (NULL);
	}
	i++; // iterate past the '\0' n '\n'
	j = 0; // new counter for malloc-ed string
	while (str[i]) // from the '\n' character, put the rest of the chars in the malloc.
		woo[j++] = str[i++];
	woo[j] = '\0'; // null byte it.
	free(str); // free the previous malloc.
	return (woo); // return the new malloc
}

/* int main()
{
    int fd;
    char *line;
    int i;
	int	nth_line;

    fd = open("invictus.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    i = 0;
    nth_line = 42;
    printf("\n");
    while (i < nth_line)
    {
        line = get_next_line(fd);
        if (line == NULL || *line == EOF)
        {
            printf("\n");
            close(fd);
            return (1);
        }
        printf("line[%d]: %s", i + 1, line);
        free(line);
        i++;
    }
    close(fd);
    printf("\n\n");
    return (0);
} */
