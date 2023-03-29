/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 21:19:46 by yel-hadd         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		fd[2];
	c_list	*cmd1;
	c_list	*cmd2;
	int		id;
	int		infile;
	int		outfile;

	//atexit(f);
	pipe(fd);
	infile = open(av[0], O_RDWR, 0644);
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC , 0644);
	av ++;
	cmd1 = ft_lstnew(ft_split(av[1], ' '), infile, fd[1]);
	cmd2 = ft_lstnew(ft_split(av[2], ' '), fd[0], outfile);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		if (execute_node(&cmd1) == 0)
			print_error("Error");
		close(fd[1]);
	}
	wait(NULL);
	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		if (execute_node(&cmd2) == 0)
			print_error("Error");
		close(fd[0]);
	}
	ft_lstclear(&cmd1);
	ft_lstclear(&cmd2);
}