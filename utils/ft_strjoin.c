/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:29:40 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/01 21:10:28 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
same strjoin as libft project, but I edited it so it will add an additional '/'
between s1 and s2
*/

/*
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki
*/

char	*ft_strjoin(char *s1, char *s2, int c)
{
	size_t	slen1;
	size_t	slen2;
	char	*join;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	join = malloc((slen1 + slen2 + c) * sizeof(char));
	if (!join)
		return (0);
	while (*s1)
		*join ++ = *s1 ++;
	if (c == 2)
		*join ++ = '/';
	while (*s2)
		*join ++ = *s2 ++;
	*join = '\0';
	if (c != 1)
		return (join - slen1 - slen2 - 1);
	return (join - slen1 - slen2);
}
