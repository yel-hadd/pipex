/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/29 20:58:21 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
#include <stdlib.h>

typedef struct commande
{
    char    **args;
    char    *path;
    int     in;
    int     out;
    struct  commande    *next;
    
}   c_list;

extern char **environ;

int     ft_strncmp(char *s1, char *s2, size_t n);
c_list	*ft_lstnew(char **args, int in, int out);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
int     execute_node(c_list **c);
int	    is_valid(c_list **c);
void	print_error(char *err);
char	**get_path_dirs(void);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*get_path(char *cmd);
void	free_2d(char **arr);

#endif