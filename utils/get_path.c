/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 21:55:54 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 21:08:39 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_path(char *cmd)
{
	char	**dirs;
	size_t	i;
	char	*tmp;
	char	*res;

	dirs = get_path_dirs();
	i = -1;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (dirs[++ i] && dirs != NULL)
	{
		tmp = dirs[i];
		dirs[i] = ft_strjoin(dirs[i], cmd, 2);
		if ((access(dirs[i], F_OK) == 0) && (access(dirs[i], X_OK) != -1))
		{
			res = ft_strdup(dirs[i]);
			return (free(tmp), free_2d(dirs), res);
		}
		free(tmp);
	}
	free_2d(dirs);
	return (NULL);
}
