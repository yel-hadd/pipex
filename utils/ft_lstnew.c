/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:35:09 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/24 23:53:05 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

c_list	*ft_lstnew(char **args, int in)
{
	c_list	*ptr;

	ptr = (c_list *)malloc(sizeof(c_list));
	if (!ptr)
		return (ptr);
	ptr->args = args;
    ptr->path = get_path(args[0]);
    ptr->in = in;
    ptr->out = 0;
	ptr->next = NULL;
	return (ptr);
}

