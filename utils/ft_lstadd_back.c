/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:49:54 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/30 16:50:40 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_lstadd_back(c_list **lst, c_list *new)
{
	c_list	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
