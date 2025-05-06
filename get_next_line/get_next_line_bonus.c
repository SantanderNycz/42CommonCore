/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:06 by lsantand          #+#    #+#             */
/*   Updated: 2025/05/05 17:15:06 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*h_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*h_read_to_buf(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res || !buffer)
		return (free(res), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			break ;
		buffer[byte_read] = '\0';
		res = h_join_and_free(res, buffer);
		if (!res || ft_strchr(buffer, '\n') || byte_read == 0)
			break ;
	}
	if (byte_read < 0)
		return (free(buffer), free(res), NULL);
	return (free(buffer), res);
}

static char	*h_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*h_trim_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc(ft_strlen(buffer + i) + 1, sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[++i])
		line[j++] = buffer[i];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = h_read_to_buf(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = h_extract_line(buffer[fd]);
	if (!line || read(fd, buffer, BUFFER_SIZE) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = h_trim_line(buffer[fd]);
	if (!buffer[fd] && line [0] == '\0')
		return (free(line), NULL);
	return (line);
}
