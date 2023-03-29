/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 22:53:51 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks pipex");
}

void	ft_lstdelone(c_list *lst)
{
	if (!lst)
		return;
	free_2d(lst->args);
	free(lst->path);
	free(lst);
}

void	ft_lstclear(c_list **lst)
{
	c_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(tmp);
		tmp = *lst;
	}
}

int	run_1st_node(c_list **c)
{
	c_list	*node;
	int		success;

	success = 0;
	node = *c;
	if (is_valid(c) == 1)
	{
    	dup2(node->in, 0);
		dup2(node->out, 1);
	}
	return (execve(node->path, node->args, NULL));
}

int	main(int ac, char **av)
{
	int		fd[2];
	c_list	*cmd1;
	//c_list	*cmd2;
	int		id;
	int		infile;
	int		outfile;

	//atexit(f);
	pipe(fd);
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC , 0644);
	av ++;
	infile = open(av[0], O_RDWR);
	cmd1 = ft_lstnew(ft_split(av[1], ' '), infile, fd[1]);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		if (run_1st_node(&cmd1) == -1)
		{
			print_error("Error");
			ft_lstclear(&cmd1);
			return (1);
		}
		close(fd[1]);
	}
	wait(NULL);
	exit(0);
	//cmd2 = ft_lstnew(ft_split(av[2], ' '), fd[0], outfile);
	//id = fork();
	//if (id == 0)
	//{
	//	if (run_2nd_node(&cmd2, fd) == 0)
	//	{
	//		print_error("Error");
	//		ft_lstclear(&cmd2);
	//		return (1);
	//	}
	//}
	//ft_lstclear(&cmd1);
	//ft_lstclear(&cmd2);
}