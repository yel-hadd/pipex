/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/24 23:56:29 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	int		infile;
	int		fd[2];
	c_list	cmd1;

	//atexit(f);
	av ++;
	cmd1 = ft_lstnew(ft_split(av[1], ' '), open(av[0], O_WRONLY));
	// infile = open(av[0], O_WRONLY);
	// if (infile == -1)
	// 	printf("bash: %s: No such file or directory\n", av[0]);
	//args = ft_split(av[1], ' ');
	err = execve("/sbin/ping", args, NULL);
	printf("%s\n", );
}