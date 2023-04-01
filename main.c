/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 01:16:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	run_node(t_list **c, int id)
{
	t_list	*node;

	if (id != 0)
		return (0);
	node = *c;
	if (node->close != -2)
		close(node->close);
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
	t_list	*list;
	t_list	*head;
	t_list	*node;
	int		id;

	if (ac != 5)
		return ((int) write(1, "Invalid Args\n", 13));
	pipe(fd);
	list = ft_lstnew(ft_split(av[2], ' '), open(av[1], O_RDWR), fd[1], fd[0]);
	node = ft_lstnew(ft_split(av[3], ' '), fd[0], \
	open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644), -2);
	ft_lstadd_back(&list, node);
	head = list;
	id = fork();
	if (run_node(&list, id) == -1)
		return (ft_lstclear(&head), print_error("Error"), 1);
	close(fd[1]);
	id = fork();
	if (run_node(&list->next, id) == -1)
		return (ft_lstclear(&head), print_error("Error"), 1);
	close(fd[0]);
	while (wait(NULL) != -1)
		;
	return (ft_lstclear(&head), 0);
}
/*
pipex.h: Error!
utils/execute_node.c: Error!
utils/ft_calloc.c: Error!
utils/ft_lstdelone.c: Error!
utils/ft_lstnew.c: Error!
utils/get_path.c: Error!
*/