/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:41:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 20:42:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
