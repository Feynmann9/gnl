/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matran-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:39:36 by matran-d          #+#    #+#             */
/*   Updated: 2023/12/11 21:43:37 by matran-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reste;
	char	buf[BUFFER_SIZE];
	char	*str;
	int	i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	while (!ft_is_next_line(buf))
	{
		read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin(str, buf);
	}
	i = ft_strlen(str);
	while (str[i] != '\n')
		str[i--];
	reste = ft_strcpy(str + 1, buf);
	return (str);
}

int	ft_is_next_line(char *str)
{	
	while (*str)
	{
		if (*str != '\n' && *str != '\0')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *dest, char *src)
{
	char	*new;

	new = malloc((ft_strlen(dest) + ft_strlen(src) + 1));
	if (!new)
		return (0);
	while (*dest)
		new++ = dest++;
	while (*src)
		new++ = src++;
	new = '\0';
	free (dest);
	return (new);
}

//fonction pour clean la range
void	ft_clean_range(char *str)
{
	
}
