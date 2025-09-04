/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:42:04 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 20:18:52 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     put_image(t_game game, char c, int x, int y)
{
    void *img;
    
    img = game.assets.bg_1;
    if (c == '1')
        img = get_wall(game, x, y);
    else if (c == '0')
        img = game.assets.bg_1;
    else if (c == 'C')
        img = game.assets.chest;
    else if (c == 'O')
        img = game.assets.chest_o;
    else if (c == 'P')
        img = game.assets.player;
    else if (c == 'E')
        img = game.assets.exit;
    mlx_put_image_to_window(game.mlx, game.mlx_win, img, x, y);
    return (0);
}

void    *get_wall(t_game *game, int x, int y)
{
    int max_x = game->cols - 1;
    int max_y = game->rows - 1;
        
    if (y < 0 || y > max_y || x < 0 || x > max_x)
        return (game->img_wall);
    if(y > 0 && g->map[y - 1][x] != '1')
        return (game->img_wall);
    if(y < max_y && g->map[y + 1][x] != '1')
        return (game->img_wall);
    if(x > 0 && g->map[y][x - 1] != '1')
        return (game->img_wall);
    if(x < max_x && g->map[y][x + 1] != '1')
        return (game->img_wall);
    return (game->img_wall);
}
