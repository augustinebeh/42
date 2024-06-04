/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/04 09:27:55 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

static char *buffer = NULL;

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
char *get_next_line(int fd)
{
    int bytes_read;
    char *line = NULL;
    char *temp = NULL;
    char *buffer_temp = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    buffer_temp = malloc(BUFFER_SIZE + 1);
    if (!buffer_temp)
        return NULL;

    line = malloc(1);
    line[0] = '\0';

    while (1)
    {
        bytes_read = read(fd, buffer_temp, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buffer_temp);
            if (bytes_read == 0 && *line == '\0')
                return NULL;
            return line;
        }
        buffer_temp[bytes_read] = '\0';
        temp = strchr(buffer_temp, '\n');
        if (temp)
        {
            *temp = '\0';
            temp++;
            buffer_temp = strdup(temp);
            temp = line;
            line = ft_strjoin(line, buffer_temp);
            free(temp);
            free(buffer_temp);
            return line;
        }
        temp = line;
        line = ft_strjoin(line, buffer_temp);
        free(temp);
    }
}

int main(void)
{
    int fd;
    char *line;

    fd = open("invictus.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
        printf("%s", line);
        free(line);
    line = get_next_line(fd);
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    close(fd);
    return (0);
}
