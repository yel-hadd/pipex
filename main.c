/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/27 15:58:31 by yel-hadd         ###   ########.fr       */
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
	dup2(node->in, STDIN_FILENO);
	dup2(node->out, STDOUT_FILENO);
	if (!is_valid(c))
		return (1);
	err = execve(node->path, node->args, NULL);
	if (err == -1)
		return (2);
	return (0);
}


int	main(int ac, char **av)
{
	int		fd[2];
	c_list	*cmd1;
	c_list	*cmd2;
	int		id;
	int		k;
	(void)	ac;

	pipe(fd);
	av ++;
	cmd1 = ft_lstnew(ft_split(av[1], ' '), open(av[0], O_RDWR, 0755), fd[1]);
	cmd2 = ft_lstnew(ft_split(av[2], ' '), fd[0], open(av[3], O_WRONLY | O_CREAT, 0755));
	id = fork();
	if (id == 0)
		k = execute(&cmd1);
	wait(NULL);
	id = fork();
	if (id == 0)
	{
		printf("%s\n", av[2]);
		k = execute(&cmd2);
	}
	
	//printf("path: %s; in: %d; out: %d;\n", cmd1->path, cmd1->in, cmd1->out);

	//atexit(f);
	// infile = open(av[0], O_WRONLY);
	// if (infile == -1)
	// 	printf("bash: %s: No such file or directory\n", av[0]);
	//args = ft_split(av[1], ' ');

}