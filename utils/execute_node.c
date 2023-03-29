/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:40:56 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 21:18:05 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	execute_node(c_list **c)
{
	int		err;
	c_list	*node;

	node = *c;
    dup2(node->in, 0);
	dup2(node->out, 1);
	if (is_valid(c) != 1)
		return (print_error("Error"), -1);
	err = execve(node->path, node->args, NULL);
	if (err == -1)
		return (2);
	return (0);
}
