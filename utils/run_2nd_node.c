/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_2nd_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:31:37 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 22:32:00 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	run_2nd_node(c_list **c, int *fd)
{
	c_list	*node;
	int		success;

	close(fd[1]);
	success = 0;
	node = *c;
    dup2(node->in, 0);
	dup2(node->out, 1);
	if (is_valid(c) == 1)
	{
		if (execve(node->path, node->args, NULL) != -1)
			success = 1;
	}
	close(fd[0]);
	if (success == 1)
		return (1);
	else
		return (0);
}
