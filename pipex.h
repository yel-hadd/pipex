/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:41 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 21:13:21 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct commande
{
	char			**args;
	char			*path;
	int				in;
	int				out;
	int				close;
	struct commande	*next;
}	t_list;

extern char	**environ;

t_list	*ft_lstnew(char **args, int in, int out, int close);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2, int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	count_words(char *s, char c);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
int		execute_node(t_list **c);
void	print_error(char *err);
char	**get_path_dirs(void);
char	*ft_strdup(char *s1);
int		is_valid(t_list **c);
char	*get_path(char *cmd);
void	free_2d(char **arr);
size_t	ft_strlen(char *s);

#endif