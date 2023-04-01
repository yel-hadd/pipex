/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:41:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 01:16:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_valid(t_list **c)
{
	t_list	*node;

	node = *c;
	if (node->args == NULL || node->path == NULL)
		return (0);
	else if (node->in == -1 || node->out == -1)
		return (0);
	return (1);
}
