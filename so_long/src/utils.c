/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:02:35 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 20:29:35 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// conta o numero de ocorrencias de um caracter
int     nb_occurrence(char **map, char c)
{
    int     count;
    int     i;
    int     j;

    i = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int     line_len(char **map)
{
    int     i;
    
    if (!map || !map[0])
        return 0;
    i = 0;
    while (map[0][i] && map[0][i] != '\n')
        i++;
    return (i);
}

int     get_ind(int pos, char **map, char directions)
{
    int     line_l;
    int     row;
    int     col;
    
    line_l = line_len(map);
    row = pos / line_l;
    col = pos % line_l;

    if (directions == 't' && row > 0)
        return (pos - line_l);
    if (directions == 'b' && row < count_lines(map) - 1)
        return (pos + line_l);
    if (directions == 'l' && col > 0)
        return (pos - 1);
    if (directions == 'r' && col < line_l - 1)
        return (pos + 1);
    return (-1);
}

int     find_index(char **map, char to_find)
{
    int     i;
    int     j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == to_find)
                return (i * line_len(map) + j);
            j++;
        }
        i++;
    }

    return (-1);
}

void    find_x_y(t_game game, int index, int *x, int *y)
{
    *y = index / game.map_w; // linha
    *x = index % game.map_w; // coluna
}

int     fill_win(t_game *game)
{
    int     x;
    int     y;

    y = 0;
    while (y < game->rows && game->map[y])
    {
        int line_len = ft_strlen(game->map[y]);
        x = 0;
        while (x < game->cols && x < line_len)
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE, y * TILE);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE, y * TILE);
            x++;
        }
        y++;
    }
    return (0);
}

void    free_map(char **map)
{
    int i;
    
    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int count_lines(char **map)
{
    int i = 0;

    if (!map)
        return 0;
    while (map[i])
        i++;
    return i;
}