/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/30 17:00:55 by yel-hadd         ###   ########.fr       */
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

void	*ft_memcpy(void *dst, void *src, size_t n);
void	ft_lstadd_back(c_list **lst, c_list *new);
int     ft_strncmp(char *s1, char *s2, size_t n);
c_list	*ft_lstnew(char **args, int in, int out);
char	*ft_strjoin(char *s1, char *s2, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_lstclear(c_list **lst);
void	ft_lstdelone(c_list *lst);
int     execute_node(c_list **c);
void	print_error(char *err);
char	**get_path_dirs(void);
char	*ft_strdup(char *s1);
int	    is_valid(c_list **c);
char	*get_path(char *cmd);
void	free_2d(char **arr);
size_t	ft_strlen(char *s);

#endif