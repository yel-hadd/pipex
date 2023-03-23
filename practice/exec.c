/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:22:03 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/23 13:48:11 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int main(void)
{
    int file = open("1.txt", O_APPEND | O_CREAT | O_WRONLY, 0777);
    int file2;
    char    *args[] = {
        "ping",
        "-c",
        "4",
        "google.com",
        NULL
    };
    int pid = fork();
    int err;
    int wstatus;

    if (pid == -1)
        return (1);
    file2 = dup2(file, 1);
    if (pid == 0)
    {
        err = execve("/sbin/ping", args, NULL);
        if (err == -1)
            return (2);
    }
    else
    {
        wait(&wstatus);
        if (WIFEXITED(wstatus))
        {
            int statuscode = WEXITSTATUS(wstatus);
            if (statuscode == 0)
                printf("success\n");
            else
                printf("failed\n");
        }
        
    }
    return (0);
}
