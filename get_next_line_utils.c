/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:34:48 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/22 13:35:33 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(char *s)
{
	size_t		size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

size_t			ft_strlcpy(char *dst, char *src, size_t dstsize)
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

char			*ft_strchr(char *s, int c)
{
	if (!s || !c)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char			*ft_strdup(char *s1)
{
	char		*str;
	int			i;

	i = 0;
	if (!(str = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	while (str[i])
		i++;
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(str = (char *)ft_calloc(sizeof(char), (s1len + s2len + 1))))
		return (NULL);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcpy(str + s1len, s2, s2len + 1);
	str[s1len + s2len] = '\0';
	if (s1)
		free(s1);
	return (str);
}
