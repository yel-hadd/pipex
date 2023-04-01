/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:35:09 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 01:19:02 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_list	*ft_lstnew(char **args, int in, int out, int close)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (ptr);
	ptr->args = args;
	ptr->path = get_path(args[0]);
	ptr->in = in;
	ptr->out = out;
	ptr->close = close;
	ptr->next = NULL;
	return (ptr);
}
