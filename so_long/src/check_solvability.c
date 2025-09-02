/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:37:52 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 17:45:56 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **dup_map(char **map)
{
    int i;
    char **copy;

    i = 0;
    while (map[i])
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

void find_player(char **map, int *py, int *px)
{
    int y;
    int x;
    
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                *py = y;
                *px = x;
                return ;
            }
            x++;
        }
        y++;
    }
    *py = -1;
    *px = -1;
}

void    spread(char **mapcpy, int y, int x, int *nb_to_find)
{
    if (mapcpy[y][x] == '1' || mapcpy[y][x] == 'V')
        return ;
    if (mapcpy[y][x] == 'C' || mapcpy[y][x] == 'E' || mapcpy[y][x] == 0)
        (*nb_to_find)--;
    mapcpy[y][x] = 'V';
    
    spread(mapcpy, y - 1, x, nb_to_find); // cima 
    spread(mapcpy, y + 1, x, nb_to_find); // baixo
    spread(mapcpy, y, x + 1, nb_to_find); // direita
    spread(mapcpy, y, x - 1, nb_to_find); // esquerda
}

int     check_map_can_be_solved(char **map, t_game *game)
{
    char    **mapcpy;
    int     nb_to_find;
    int     py;
    int     px;
    int     i;
    
    mapcpy = dup_map(map);
    if (!mapcpy)
        return (close_program(game), 0);

    nb_to_find = nb_occurrence(map, 'C');
    nb_to_find += nb_occurrence(map, 'E');

    find_player(map, &py, &px);
    if (py == -1 || px == -1) // sem player
        return(free_map(mapcpy), EXIT_FAILURE);
 
    spread(mapcpy, py, px, &nb_to_find);
    
    i = 0;
    while (mapcpy[i])
        free(mapcpy[i++]);
    free(mapcpy);

    if (nb_to_find == 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}