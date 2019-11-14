/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:34:48 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/14 11:42:32 by thgermai         ###   ########.fr       */
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

t_line		*ft_lstnew(char *str)
{
	t_line		*line;
	char		*temp;

	temp = ft_strjoin(NULL, str, ft_strlen(str));
	if (!(line = malloc(sizeof(t_line) * 1)))
		return (NULL);
	line->line = temp;
	line->next = NULL;
	return (line);
}

void		ft_listadd_back(t_line **list, t_line *new)
{
	t_line		*temp;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		new->next = NULL;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

char		*ft_strjoin(char *s1, char *s2, int size)
{
	int		s1len;
	int		s2len;
	char 	*str;

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
