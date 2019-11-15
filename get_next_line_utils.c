/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:34:48 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/15 16:11:41 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	locate;

	i = 0;
	locate = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
	{
		if (i < dstsize)
		{
			dst[i] = src[i];
			locate = i + 1;
		}
		i++;
	}
	if (i >= dstsize)
		locate = dstsize - 1;
	if (dstsize != 0)
		dst[locate] = '\0';
	return (i);
}

char		*ft_strjoin(char *s1, char *s2, int size)
{
	int		s1len;
	int		s2len;
	char 	*str;

	(void)size;
	if (!s1)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, s1len + 1);
	ft_strlcpy(str + s1len, s2, size + 1);
	str[s1len + s2len] = '\0';
	return (str);
}
