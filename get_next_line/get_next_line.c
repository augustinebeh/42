/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/04 00:47:20 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char *static_line = NULL;
static size_t static_size = 0;
static size_t static_index = 0;

char *get_next_line(int fd)
{
    char buffer;
    char *line;
    ssize_t bytes_read;
    size_t i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (fcntl(fd, F_GETFL) == -1 || !(fcntl(fd, F_GETFL) & O_RDONLY))
        return (NULL);
    if (static_line == NULL) {
        static_line = calloc(BUFFER_SIZE + 1, sizeof(char));
        if (static_line == NULL)
            return (NULL);
        static_size = BUFFER_SIZE;
        static_index = 0;
    }
    line = static_line;
    i = static_index;
    while (1) {
        bytes_read = read(fd, &buffer, 1);
        if (bytes_read <= 0)
            break;
        line[i++] = buffer;
        if (buffer == '\n')
            break;
        if (i == static_size) {
            static_size += BUFFER_SIZE;
            static_line = realloc(static_line, static_size + 1);
            if (static_line == NULL)
                return (NULL);
        }
    }
    if (i == 0 && bytes_read <= 0) {
        free(static_line);
        static_line = NULL;
        return (NULL);
    }
    line[i] = '\0';
    static_index = i;
    if (bytes_read <= 0) {
        line = ft_strdup(static_line);
        free(static_line);
        static_line = NULL;
    }
    return (line);
}

/* int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i <= len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
} */

int main()
{
    int fd1, fd2, fd3;
    char *line;

    fd1 = open("tests/test.txt", O_RDONLY);
    fd2 = open("tests/test2.txt", O_RDONLY);
    fd3 = open("tests/test3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
        perror("open");
        return 1;
    }

    printf("Testing file 1:\n");
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line);
    }

    printf("\nTesting file 2:\n");
    while ((line = get_next_line(fd2)) != NULL) {
        printf("%s", line);
        free(line);
    }

    printf("\nTesting file 3:\n");
    while ((line = get_next_line(fd3)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
