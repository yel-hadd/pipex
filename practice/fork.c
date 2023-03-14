/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:52:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/14 12:04:15 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int id;

	id = fork();
	if (id == 0)
		printf("Your are on the child process %d\n", id);
	else if (id > 0)
		printf("Your are on the main process %d\n", id);
	else if (id == -1)
		printf("Error\n");

}