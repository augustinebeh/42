/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/07 02:55:49 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == find)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
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
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

char *get_next_line(int fd)
{
	static char *balance = NULL;
	char *return_line;
	char *buffer;
	ssize_t read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	return (NULL);
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1); // null terminate the entire string before hand so i dont need to find the exact spot to '\0' it
		read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
        {
            free(buffer);
            if (balance != NULL)
            {
                return_line = balance;
                balance = NULL;
                return (return_line);
            }
            return (NULL);
        }
		if (balance == NULL)
			balance = ft_strdup("");
		char *temp = ft_strjoin(balance, buffer);
      free(balance);
      balance = temp;
		if (ft_strchr(balance, '\n'))
		{
			return_line = ft_substr(balance, 0, (ft_strchr(balance, '\n') -	balance + 1));
			temp = ft_strdup(ft_strchr(balance, '\n') + 1);
			free(balance);
     		balance = temp;
			free(buffer);
			return (return_line);
		}
	}
	free(buffer);
}

int main()
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
      if (line == NULL)
      {
         printf("\n");
         close(fd);
         break;
      }
      printf("line[%d]: %s", (i + 1), line);
		free(line);
      i++;
   }
   close(fd);
   return (0);
}

