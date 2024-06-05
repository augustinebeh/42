/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_workingfile.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:21:02 by abeh              #+#    #+#             */
/*   Updated: 2024/06/05 23:01:14 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif


// char *gnl_creation(int fd, char *balance, char *buffer)
// {
// 	size_t bytes_read;
// 	char *temp;
	
// 	bytes_read = 1; //used as a checker
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE); // secondary checker
// 		if (bytes_read == -1) //error checking. if bytes_read is -1
// 		{
// 			free(balance);
// 			return NULL;
// 		}
// 		else if (bytes_read == 0) // if it is 0 we will know that we have reached the end of the file
// 			break;
// 		buffer[bytes_read] = '\0';
// 		if (balance == NULL)
// 			balance = ft_strdup("");
// 		temp = balance;
// 		balance = ft_strjoin(temp, buffer);
// 		free(temp);
// 		temp = NULL;
// 		if (ft_strchr(buffer, '\n'))
// 		break;
// 	}
// 	return (balance);
// }
// char *get_next_line(int fd)
// {
// 	static char *balance; // remaining characters after the '\n' char
// 	char *line; // the final return output of this function
// 	char *buffer; //temporary variable to manipulate the strings

// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char)); // 2.
// 	if (!buffer)
// 		return (NULL);
// 	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0); // handles the errors if fd ivalid/ buffersize less than 0, file able to open
// 	{
// 		free(balance);
// 		free(buffer);
// 		balance = NULL;
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	if(!buffer)
// 		return (NULL);
//}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
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

char *get_next_line(int fd)
{
	static char *balance;
	char *line;
	char *buffer;
	ssize_t bytes_read;
	char* uwu;

	buffer = (char*)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
	{
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(balance);
		balance = NULL;
		buffer = NULL;
		return (NULL);
	}


	/* start of bytes_read loop*/
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", bytes_read);
	printf("%s\n", buffer);
	
	if (bytes_read < 0)
	{
		free(buffer);
		free(balance);
		balance = NULL;
		buffer = NULL;
		return (NULL);
	}
	printf("%d\n", bytes_read);
	buffer[bytes_read] = '\0'; // null terminate the string
	
	/*check for NL*/
	/* return NL, store remainder in global variable*/
	if (ft_strchr(buffer, '\n') == NULL)
	{
		uwu =ft_strjoin(line, buffer);
	}
	printf("1%s\n", buffer);
	printf("2%s\n", line);
	printf("1%s\n", uwu);
	
	/*end of bytes_read loop*/

	/* read fail `-1` case*/
	/* EOF without newline case*/
	return(0);
}


	
	/**
 * 1. read the file from the file descriptor up till the buffersize, or until a '\0' 
 * 2. put the string into a malloc based on buffersize + 1 (call it line).
 * 3. check the string if there are any '\n' characters inside.
 * 4. if no, repeat 1 & 2. line = line + newstr.
 * 5. if yes, find the first occurence of the '\n' character.
 * 6. malloc from the start of the string to the first occurenc of the '\n' call it temp
 * 7. line = line + temp.
 * 7. keep the rest of the string into static char* balance.
 * 8. return the value of line
 * 
*/

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
}