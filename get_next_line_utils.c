/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:34:48 by thgermai          #+#    #+#             */
/*   Updated: 2019/11/13 16:19:23 by thgermai         ###   ########.fr       */
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

char		*ft_strjoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	char 	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
		j = 0;
	}
	while (s2[j] && j < size)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
