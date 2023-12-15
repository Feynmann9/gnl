/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matran-d <matran-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:31:37 by matran-d          #+#    #+#             */
/*   Updated: 2023/12/15 21:04:17 by matran-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	
	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (unsigned char)c)
	{
		return ((char *)(str + i));
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	// int		j;
	char	*str;
	int		len;
	
	// if (!s1)
	// 	return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	// j = 0;
	// while (s2[j])
	// 	str[i++] = s2[j++];
	str[len] = 0;
	// free(s2);pense a free lancien malloc de range;
	return (str);
}
