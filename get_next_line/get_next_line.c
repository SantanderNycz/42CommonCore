/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:13:56 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/29 18:35:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

<<<<<<< HEAD
// join e free
static char		*h_free(char *s, char *buf)
{
	char	*temp;

	temp = ft_strjoin(s, buf);
	free(s);
	return (temp);
}

// deleta a linha encontrada
static char		*h_find(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0,
	// len da primeira linha
	while (s[i] && s[i] != '\n')
		i++;
	// se terminar com \0, entao retorna Null
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	//(len do arquivo) - (len da primeira linha + 1)
	line = ft_calloc((ft_strlen(s) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (s[i])
		line[j++] = s[i++];
	free(s);
	return (line);
}

// retorna a linha
static char		*h_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	// se não tiver linha, retorna Null
	if (!s[i])
		return (NULL);
	// vai até o '\0'
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	// se S terminar em '\0' ou '\n', troca o fim da linha por '\n'
	if (s[i] && s[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char		*h_read_file(int fd, char *res)
{
	char 	*s;
	int		byte_read;

	//malloc se o res não existir
	if (!res)
		res = ft_calloc(1, 1);
	//malloc para S
	s = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		//enquanto o fim da linha nao for lido
		byte_read = read(fd, s, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(s);
			return (NULL);
		}
		// 0 para o fim, para evitar mem leak
		s[byte_read] = 0;
		// join e free
		res = h_free(res, s);
		// para se encontrar a '\n'
		if (ft_strchr(s, '\n'))
			break;
	}
	free(s);
	return (res);
=======
static char	*read_file(int fd, char *backup)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(backup, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			break ;
		buffer[read_bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	if (read_bytes < 0)
		return (NULL);
	else
		return (backup);
}

static char	*get_line(char *backup)
{
	char	*line;
	size_t	size;

	if (!backup)
		return (NULL);
	size = 0;
	while (backup[size] && backup[size] != '\n')
		size++;
	line = (char *)malloc(sizeof(char) * (size + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, size + 1);
	if (backup[size] == '\n')
		line[size++] = '\n';
	line[size] = '\0';
	return (line);
}

static char	*remove_read_line(char *backup)
{
	int		i;
	int		j;
	char	*new_backup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!new_backup)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
>>>>>>> 8a671c5251df3b4f96d90edd7a1aac1591c7159d
}

char	*get_next_line(int fd)
{
<<<<<<< HEAD
	static char	*s;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	s = h_read_file(fd, s);
	if (!s)
		return (NULL);
	line = h_line(s);
	s = h_find(s);
	return (line);
}
=======
	char	*line;
	char	*backup;

	backup = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup = read_file (fd, backup);
	if (!backup)
		return (NULL);
	line = get_line(backup);
	backup = remove_read_line(backup);
	return (line);
}
>>>>>>> 8a671c5251df3b4f96d90edd7a1aac1591c7159d
