/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:11:57 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/30 21:11:57 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			break ;
	}
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*s[FOPEN_MAX];
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	s[fd] = h_read_file(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = h_line(s[fd]);
	s[fd] = h_find(s[fd]);
	return (line);
}
