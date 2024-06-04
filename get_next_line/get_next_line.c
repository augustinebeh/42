/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/05 04:13:03 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_next_str(char *str);
char *ft_read(int fd, char *str);
char *get_next_line(int fd);
char *ft_line(char *str);

char *ft_read(int fd, char *str)
{
    char *buff;
    int bytes;
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    bytes = 1;
    while (!ft_strchr(str, '\n') && bytes != 0)
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[bytes] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}

char *get_next_line(int fd)
{
    char *line;
    static char *str;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str = ft_read(fd, str);
    if (!str)
        return (NULL);
    line = ft_line(str);
    str = ft_next_str(str);
    return (line);
}

// char *ft_line(char *str)
// {
//     int i;
//     char *tab;
    
//     i = 0;
//     if (!str[i])
//         return (NULL);
//     while (str[i] && str[i] != '\n')
//         i++;
//     tab = (char *)malloc(sizeof(char) * (i + 2));
//     if(!tab)
//         return (NULL);
//     i = 0;
//     while (str[i] && str[i] != '\n')
//     {
//         tab[i] = str[i];
//         i++;
//     }
//     if (str[i] == '\n')
//     {
//         tab[i] = str[i];
//         i++;
//     }
//     tab[i] = '\0';
//     return (tab);
// }

char *ft_line(char *str)
{
    int i;
    char *tab;
    
    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    tab = (char *)malloc(sizeof(char) * (i + 1));
    if(!tab)
        return (NULL);
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

char *ft_next_str(char *str)
{
    int i;
    int j;
    char *tab;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!tab)
        return (NULL);
    i++;
    j = 0;
    while (str[i])
        tab[j++] = str[i++];
    tab[j] = '\0';
    free(str);
    return (tab);
}

int main()
{
    int fd;
    char *line;

    fd = open("invictus.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }

    int i;
    i = 0;
    int nth_line = 42;
    printf("\n");
    while (i < nth_line)
    {
        line = get_next_line(fd);
        if (line == NULL || *line == EOF)
        {
            perror("get_next_line");
            close(fd);
            return (1);
        }
        printf("line[%d]: %s",i+1 , line);
        free(line);
        i++;
    }

    close(fd);
    printf("\n\n");

    return (0);
}