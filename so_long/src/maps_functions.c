/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:27:36 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 18:13:40 by lsantand         ###   ########.fr       */
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

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return NULL;

    // conta linhas e largura do mapa
    *height = 0;
    *width = 0;
    while ((line = get_next_line(fd)))
    {
        if (*width == 0)
            *width = ft_strlen(line) - 1; // remove \n
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
        map[i] = ft_strndup(line, *width); // duplica só os chars válidos
        free(line);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return map;
}