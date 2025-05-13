/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:06 by lsantand          #+#    #+#             */
/*   Updated: 2025/05/07 18:09:38 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*h_join_and_free(char *buffer, char *buf, int byte_read)
{
	char	*temp;
	char	*buf_temp;
	int		i;

	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (free(buffer), NULL);
		buffer[0] = '\0';
	}
	buf_temp = (char *)malloc(sizeof(char) * (byte_read + 1));
	if (!buf_temp)
		return (free(buffer), NULL);
	i = 0;
	while (i < byte_read)
	{
		buf_temp[i] = buf[i];
		i++;
	}
	buf_temp[byte_read] = '\0';
	temp = ft_strjoin(buffer, buf_temp);
	free(buffer);
	free(buf_temp);
	return (temp);
}

static char	*h_read_to_buf(int fd, char	*buffer, char *buf)
{
	int		byte_read;

	byte_read = 1;
	while (byte_read > 0 && (!buffer || !ft_strchr(buffer, '\n')))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buf), free(buffer), NULL);
		buf[byte_read] = '\0';
		if (byte_read > 0)
		{
			buffer = h_join_and_free(buffer, buf, byte_read);
			if (!buffer)
				return (NULL);
		}
	}
	return (free(buf), buffer);
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
	if (j == 0)
		return (free(line), free(buffer), NULL);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*buf;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(buf), NULL);
	buffer[fd] = h_read_to_buf(fd, buffer[fd], buf);
	if (!buffer[fd])
		return (NULL);
	line = h_extract_line(buffer[fd]);
	if (!line)
		return (free(buffer[fd]), (buffer[fd] = NULL), NULL);
	buffer[fd] = h_trim_line(buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	buf = NULL;
	return (line);
}
