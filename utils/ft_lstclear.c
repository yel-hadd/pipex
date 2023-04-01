/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:47:26 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 01:16:08 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(tmp);
		tmp = *lst;
	}
}
