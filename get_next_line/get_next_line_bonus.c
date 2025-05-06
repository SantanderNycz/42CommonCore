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

	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!buf)
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*h_read_to_buf(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && (!res || !ft_strchr(res, '\n')))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			if (res)
				free(res);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		res = h_join_and_free(res, buffer);
		if (!res)
			break ;
	}
	free(buffer);
	return (res);
}

static char	*h_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
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
	line[i] = '\0';
	return (line);
}

static char	*h_trim_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!line)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = h_read_to_buf(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = h_extract_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = h_trim_line(buffer[fd]);
	return (line);
}
