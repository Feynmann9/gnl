/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matran-d <matran-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:31:21 by matran-d          #+#    #+#             */
/*   Updated: 2023/12/16 00:41:02 by matran-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>
//#include <stdio.h>

char	*ft_maj_range(char *range)
{
	char	*str;
	int		i;

	i = 0;
	if (!range[i])
		return (NULL);
	while (range[i] && range[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (range[i] && range[i] != '\n')
	{
		str[i] = range[i];
		i++;
	}
	if (range[i] == '\n')
	{
		str[i] = range[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_lire_range(int fd, char *range)
{
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(range, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		range = ft_strjoin(range, buff);
	}
	free(buff);
	return (range);
}

char	*ft_second_range(char *range)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!range[i])
	{
		free(range);
		return (NULL);
	}
	while (range[i] && range[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(range) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (range[i])
		str[j++] = range[i++];
	str[j] = '\0';
	free(range);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*range;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	range = ft_lire_range(fd, range);
	if (!range)
		return (NULL);
	line = ft_maj_range(range);
	range = ft_second_range(range);
	return (line);
}

/*int 	main(void)
{
	int fd;
	char *str;

	fd = open ("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("|%s|", str);
	while (str)
	{
		printf("|%s|", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}
*/