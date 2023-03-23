/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:05:48 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/03/23 16:07:33 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	free_all(char **s, size_t index)
{
	while (index)
	{
		free(s[index]);
		index --;
	}
	free(s);
}

static char	**allocate(char **result, size_t i, char const *s, char c)
{
	result[i] = (char *) malloc((word_len(s, c) + 1) * sizeof(char));
	if (!result[i])
	{
		free_all(&result[i], i);
		return (NULL);
	}
	ft_memcpy(result[i], s, word_len(s, c));
	result[i][word_len(s, c)] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	char	**result;

	i = 0;
	if (!s)
		return ((char **) NULL);
	count = count_words((char *) s, c);
	result = (char **) malloc((count + 1) * sizeof(char *));
	if (!result)
		return (result);
	while (i < count)
	{
		while (*s == c && *s)
			s ++;
		result = allocate(result, i, s, c);
		if (!result)
			return (NULL);
		i ++;
		while (*s != c && *s)
			s++;
	}
	result[i] = (char *) NULL;
	return (result);
}
