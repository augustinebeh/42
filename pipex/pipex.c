/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 04:52:55 by abeh              #+#    #+#             */
/*   Updated: 2024/07/07 20:07:58 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Sends the output of the first command against the file
 * to the write end of the pipe.
 * close the read end on the pipe, this is called the child process
 *
 * apply the next command to the read end of the pipe
 * close the write end of the pipe
 *
 * in the fork() function there will be an if else statement
 * not conventional. both if and else statements will be run.
 *
 * if the return value of fork is 0,
 * that determines that it's the child process
 *
 * if the return value of fork is the child process's id,
 * it means that its the parent process.
 */


#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    char *args[4];

    args[0] = "wc";
    args[1] = "-l";
    args[2] = NULL; // No input file, read from stdin

    int fd = open("ping.txt", O_WRONLY | O_CREAT, 0644);
    char hello[33] = "hello my name is beh yooo";
    char **bye = ft_split(hello, ' ');

    // Create a pipe
    int pipe_fds[2];
    pipe(pipe_fds);

    // Fork a child process
    if (fork() == 0) {
        // Child process: write to the pipe
        close(pipe_fds[0]); // Close reading end
        dup2(pipe_fds[1], 1); // Duplicate writing end to stdout

        // Write the output of ft_split to the pipe
        int i = 0;
        while (bye[i]) {
            printf("%s\n", bye[i]);
            i++;
        }
    } else {
        // Parent process: read from the pipe
        close(pipe_fds[1]); // Close writing end
        dup2(pipe_fds[0], 0); // Duplicate reading end to stdin

        // Execute wc with the input from the pipe
        dup2(fd, 1); // Duplicate file descriptor to stdout
        dup2(fd, 2); // Duplicate file descriptor to stderr
        execve("/usr/bin/wc", args, NULL);
      //   printf("fkc");
    }

   //  return 0;
}
