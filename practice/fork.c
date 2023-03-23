/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:52:36 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/21 20:35:56 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int	arr[] = { 10, 10, 10, 10, 10, 50};
	int arrSize = sizeof(arr) / sizeof(int);
	int	fd[2];
	int	id;
	int start, end;
	int i;
	int sum = 0;
	int childsum = 0;
	
	if (pipe(fd) == -1)
		return (write(1, "P-ERR\n", 5), 1);
	id = fork();
	if (id == -1)
		return (write(1, "F-ERR\n", 5), 1);
	if (id == 0)
	{
		start = arrSize / 2;
		end = arrSize;
		i = start;
		close(fd[0]);
		while (i < end)
			sum += arr[i++];
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else if (id != 0) {
		close(fd[1]);
		start = 0;
		end = start + (arrSize / 2);
		i = start;
		while (i < end)
			sum += arr[i++];
		read(fd[0], &childsum, sizeof(childsum));
	}
	wait(NULL);
	if (id != 0)
		printf("%d\n", sum+childsum);
	return (0);
}