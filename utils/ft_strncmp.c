/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:57:40 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/24 20:58:12 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *) s1;
	uc2 = (unsigned char *) s2;
	i = 0;
	while ((uc1[i] || uc2[i]) && i < n)
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i ++;
	}
	return (0);
}
