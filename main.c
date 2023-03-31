/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/31 00:50:00 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks pipex");
}

int	run_node(c_list **c)
{
	c_list	*node;

	node = *c;
	if (is_valid(c) == 1)
	{
		dup2(node->in, 0);
		dup2(node->out, 1);
		return (execve(node->path, node->args, NULL));
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int		fd[2];
	c_list	*list;
	int		id;

	pipe(fd);
	list = ft_lstnew(ft_split(av[2], ' '), open(av[1], O_RDWR), fd[1]);
	ft_lstadd_back(&list, ft_lstnew(ft_split(av[3], ' '), fd[0], open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC , 0644)));
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		if (run_node(&list) == -1)
		{
			print_error("Error");
			return (1);
		}
	}
	close(fd[1]);
	list = list->next;
	id = fork();
	if (id == 0)
	{
		if (run_node(&list) == -1)
		{
			print_error("Error");
			return (1);
		}
	}
	close(fd[0]);
	while (wait(NULL) != -1) ;
	ft_lstclear(&list);
	exit(0);
}