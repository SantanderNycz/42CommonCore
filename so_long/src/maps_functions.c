/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:27:36 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 20:14:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     get_map_size(t_game *game, char *filename)
{
    int     fd;
    char    c;
    int     i;
    int     rt_val;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (ft_printf_e(ER_NOMAP), close_program(game), 0);
    rt_val = 1;
    while (rt_val)
    {
        rt_val = read(fd, &c, 1);
        if (rt_val == -1)
            return (close_program(game),0);
        if (rt_val == 1)
            i++;
    }
    close (fd);
    return (i);
}

char **get_map(char *file, int *height, int *width)
{
    int     fd;
    char    *line;
    char    **map;
    int     i;
    int     len;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;

    *height = 0;
    *width = 0;
    while ((line = get_next_line(fd)))
    {
        len = ft_strlen(line);
        if (len && line[len - 1] == '\n')
            len--;
        if (*width == 0)
            *width = (int)len;
        else if ((int)len != *width)
        {
            free(line);
            close(fd);
            return (NULL); // mapa não retangular
        }
        free(line);
        (*height)++;
    }
    close(fd);

    map = malloc(sizeof(char *) * (*height + 1));
    if (!map)
        return NULL;
    fd = open(file, O_RDONLY);
    i = 0;
    while ((line = get_next_line(fd)))
    {
        len = ft_strlen(line);
        if (len && line[len - 1] == '\n')
            len--;
        map[i] = ft_strndup(line, len);
        free(line);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return map;
}