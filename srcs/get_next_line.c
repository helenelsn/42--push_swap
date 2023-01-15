/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:00:54 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/15 20:14:38 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	parse_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

void	save_buffer(char *buffer, int len)
{
	int	i;
	int	len_max;

	i = 0;
	len_max = BUFFER_SIZE - len;
	while (i < len_max)
	{
		buffer[i] = buffer[len + i];
		i++;
	}
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_line(int fd, char *buffer, char *line, int index_n)
{
	int	bytes_read;

	bytes_read = ft_strlen(buffer);
	line = ft_strncat(line, buffer, index_n + 1);
	if (!line)
		return (NULL);
	while (bytes_read > 0 && buffer[index_n] != '\n')
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		index_n = parse_buffer(buffer);
		line = ft_strncat(line, buffer, index_n + (buffer[index_n] == '\n'));
	}
	save_buffer(buffer, index_n + (buffer[index_n] == '\n'));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[(BUFFER_SIZE + 1) * (BUFFER_SIZE > 0)];
	char		*line;
	int			index_n;
	int			bytes_read;

	index_n = 0;
	bytes_read = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (*buffer == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			return (NULL);
		buffer[bytes_read] = '\0';
	}
	index_n = parse_buffer(buffer);
	return (get_line(fd, buffer, line, index_n));
}
