/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:02:35 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/01 22:07:14 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// conta o numero de ocorrencias de um caracter
int     nb_occurrence(char *str, char c)
{
    int     count;
    size_t     i;

    i = 0;
    count = 0;
    if (!str)
        return 0;
    while (str[i++])
    {
        if (str[i] == c)
            count++;
    }
    return (count);
}

int     line_len(char *str)
{
    int     i;
    
    i = 0;
    if (!str)
        return 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (i);
}

int     get_ind(int pos, char *map, char directions)
{
    int     line_l;
    
    line_l = line_len(map) + 1;
    if (map[pos] == '\n')
        return (-1);
    if (directions == 't')
        if (pos > line_l)
            return (pos - line_l);
    if (directions == 'b')
        if (pos > line_l * nb_occurrence(map, '\n'))
            return (pos + line_l);
    if (directions == 'l')
        if (map[pos - 1] && map[pos - 1] != '\n')
            return (pos - 1);
    if (directions == 'r')
        if (map[pos + 1] && map[pos + 1] != '\n')
            return (pos + 1);
    return (-1);
}

int     find_index(char *map, char to_find)
{
    int     i;
    
    i = 0;
    while (map[i] && map[i] != to_find)
        i++;
    if (map[i] == to_find)
        return (i);
    return (-1);
}

int     find_x_y(t_game game, int pos, int *x, int *y)
{
    int     i;
    
    i = 0;
    *x = 0;
    *y = 0;
    while (game.map[i] && i < pos)
    {
        if (game.map[i] == '\n')
        {
            *y = *y + 1;
            *x = 0;
        }
        else
            *x = *x + 1;
        i++;
    }
    return (0);
}