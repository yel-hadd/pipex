/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:55:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/24 21:55:23 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path_dirs(void)
{
	char	*tmp;
	char	**directories;
	int		i;

	while (*environ)
	{
		if (ft_strncmp(*environ, "PATH=", 5) == 0)
		{
			tmp = *environ;
			directories = ft_split(tmp + 5, ':');
			return (directories);
		}
		environ ++;
	}
	return (NULL);
}
