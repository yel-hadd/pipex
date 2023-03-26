/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/26 21:13:21 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks a.out");
}


int	is_valid(c_list **c)
{
	c_list	*node;

	node = *c;
	if (node->args == NULL || node->path == NULL)
		return (0);
	if (node->in == -1 || node->out == -1)
		return (0);
	return (1);
}

int	execute(c_list **c)
{
	int	err;
	c_list	*node;

	node = *c;
	if (!is_valid(c))
		return (1);
	err = execve(node->path, node->args, NULL);
	if (err == -1)
		return (2);
	return (0);
}


int	main(int ac, char **av)
{
	int		infile;
	int		outfd;
	int		fd[2];
	c_list	*cmd1;
	int		id;
	int		k;

	pipe(fd);
	//outfd = dup2(fd[1], 1);
	av ++;
	cmd1 = ft_lstnew(ft_split(av[1], ' '), open(av[0], O_WRONLY), fd[1]);
	id = fork();
	if (id == 0)
	{
		k = execute(&cmd1);
		printf("%d\n", k);
	}
	//printf("path: %s; in: %d; out: %d;\n", cmd1->path, cmd1->in, cmd1->out);

	//atexit(f);
	// infile = open(av[0], O_WRONLY);
	// if (infile == -1)
	// 	printf("bash: %s: No such file or directory\n", av[0]);
	//args = ft_split(av[1], ' ');

}