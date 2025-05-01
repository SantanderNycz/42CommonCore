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

// join e free
static char		*h_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char		*h_read_to_buf(int fd, char *res)
{
	char 	*buffer;
	int		byte_read;

	//malloc se o res não existir
	if (!res)
		res = ft_calloc(1, 1);
	//malloc para Buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		//enquanto o não chegar o fim do arquivo, lê
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 para o fim, para evitar mem leak
		buffer[byte_read] = 0;
		// join e free
		res = h_join_and_free(res, buffer);
		// para se encontrar a '\n'
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

// retorna a linha
static char		*h_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	// se não tiver linha, retorna Null
	if (!buffer[i])
		return (NULL);
	// Conta quantos caracteres há até \n ou \0
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// Aloca espaço suficiente par a linha + \0
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	// Copia os caracteres de linha para o novo ponteiro
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// se Buffer terminar em '\0' ou '\n', troca o fim da linha por '\n'
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// deleta a linha encontrada
static char		*h_trim_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// len da primeira linha
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// se for \0, entao retorna Null
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	//(len do arquivo) - (len da primeira linha + 1)
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = h_read_to_buf(fd, buffer);
	if (!buffer)
		return (NULL);
	line = h_extract_line(buffer);
	buffer = h_trim_line(buffer);
	return (line);
}
