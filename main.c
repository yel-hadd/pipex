/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/28 01:20:07 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f()
{
	system("leaks a.out");
}

void	ft_lstdelone(c_list *lst)
{
	if (!lst)
		return ;
	free_2d(lst->args);
	free(lst->path);
	free(lst);
}

void	ft_lstclear(c_list **lst, void (*del)(void*))
{
	c_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(tmp);
		tmp = *lst;
	}
}

void	print_error(int check, c_list **c)
{
	if (check == -1)
		perror("Error: Invalid arguments");
	else if (check == -2)
		perror("Error: Command not found");
	else if (check == -3)
		perror("Error: Failed to open file");
	else if (check == -4)
		perror("Error: Failed to open file");
}

int	is_valid(c_list **c)
{
	c_list	*node;
	int		valid;

	valid = 1;
	node = *c;
	if (node->args == NULL)
		return (-1);
	else if (node->path == NULL)
		return (-2);
	else if (node->in == -1)
		return (-3);
	else if (node->out == -1)
		return (-4);
	return (1);
}

int	execute(c_list **c)
{
	int		err;
	c_list	*node;
	int		check;

	node = *c;
	check = is_valid(c);
	if (check != 1)
		return (print_error(check, c), -1);
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
	cmd1 = ft_lstnew(ft_split(av[1], ' '), open(av[0], O_RDWR, 0644), fd[1]);
	cmd2 = ft_lstnew(ft_split(av[2], ' '), fd[0], open(av[3], O_WRONLY | O_CREAT | O_TRUNC , 0644));
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(cmd1->in, 0);
		dup2(cmd1->out, 1);
		k = execute(&cmd1);
		if (k == 0)
			write(1, "ERROR\n", 6);
		close(fd[1]);
	}
	wait(NULL);
	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(cmd2->out, 1);
		k = execute(&cmd2);
		if (k == 0)
			write(1, "ERROR\n", 6);
		close(fd[0]);
	}
}