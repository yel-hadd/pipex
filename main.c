/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:48:32 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/23 16:23:03 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int		infile;
	int		fd[2];
	char	**args;

	av ++;
	infile = open(av[0], O_WRONLY);
	if (infile == -1)
		printf("bash: %s: No such file or directory\n", av[0]);
	//args = ft_split(av[1], ' ');

	while (*environ)
	{
		printf("%s\n", *environ);
		environ ++;
	}
}