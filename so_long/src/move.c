/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:44:14 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 19:13:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     move_check(t_game *game, char direction)
{
    int     temp_i = get_ind(game->player_pos, game->map, direction);
    int     row = temp_i / game->map_w;
    int     col = temp_i % game->map_w;

    if (temp_i == -1)
        return (-1);
    char dest = game->map[row][col];
    if (dest == '1')
        return 0;
    if (dest == 'C')
    {
        game->collect--;
        move_player(game, game->player_pos, direction);
    }
    else if (dest == '0' || dest == 'P' || dest == 'O' || dest == 'E')
        move_player(game, game->player_pos, direction);
    if (dest == 'E' && game->collect == 0)
        return (close_program(game), 0);
    
    game->player_pos = temp_i;
    game->move++;
    return 0;
}

int     move_player(t_game *game, int from_pos, char direction)
{
    int     row = from_pos / game->map_w;
    int     col = from_pos % game->map_w;
    int     x = 0;
    int     y = 0;
    
    x = x * 96;
    y = y * 96;
    put_image(*game, '0', x, y);
    char from_cell = game->map[row][col];
    if (from_cell == 'C' || from_cell == 'O')
    {
        put_image(*game, 'O', x, y);
        game->map[row][col] = 'O';
    }
    else if (from_cell == 'E')
        put_image(*game, 'E', x, y);
    if (direction == 't')
        y -= 96;
    else if (direction == 'b')
        y += 96;
    else if (direction == 'r')
        x += 96;
    else if (direction == 'l')
        x -= 96;
    ft_printf("Número de movimentos: %d\n", ++game->move);
    put_image(*game, 'P', x, y);
    return 0;
}
