/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solvability.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:37:52 by lsantand          #+#    #+#             */
/*   Updated: 2025/08/12 17:44:34 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char    *spread(char *mapcpy, int pos, int *nb_to_find)
{
    int temp_i;
    
    if (mapcpy[pos] == 'C' || mapcpy[pos] == 'E')
        *nb_to_find = *nb_to_find - 1;
    if (mapcpy[pos] == 'C' || mapcpy[pos] == 'E' || mapcpy[pos] == '0')
        mapcpy[pos] = '1';
    temp_i = get_ind(pos, mapcpy, 't');
    if (temp_i != -1 && mapcpy[temp_i] != '-1')
        spread(mapcpy, temp_i, nb_to_find);
    temp_i = get_ind(pos, mapcpy, 'b');
    if (temp_i != -1 && mapcpy[temp_i] != '-1')
        spread(mapcpy, temp_i, nb_to_find);
    temp_i = get_ind(pos, mapcpy, 'l');
    if (temp_i != -1 && mapcpy[temp_i] != '-1')
        spread(mapcpy, temp_i, nb_to_find);
    temp_i = get_ind(pos, mapcpy, 'r');
    if (temp_i != -1 && mapcpy[temp_i] != '-1')
        spread(mapcpy, temp_i, nb_to_find);
    return (mapcpy);
}

int     check_map_can_be_solved(char *map, t_game *game)
{
    char    *mapcpy;
    int     nb_to_find;
    
    mapcpy = ft_strdup(map);
    if (!mapcpy)
        return (close_program(game), 0);
    nb_to_find = 0;
    nb_to_find = nb_occurrence(map, 'C');
    nb_to_find += nb_occurrence(map, 'E');
    mapcpy = spread(mapcpy, find_index(map, 'P'), &nb_to_find);
    free(mapcpy);
    if (nb_to_find == 0);
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}