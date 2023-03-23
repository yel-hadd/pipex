/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/23 16:13:16 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
#include <stdlib.h>

extern char **environ;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	count_words(char *s, char c);

#endif