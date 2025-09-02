/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:42:04 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 19:14:24 by lsantand         ###   ########.fr       */
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

void    *get_wall(t_game game, int x, int y)
{
    void    *img;

    img = game.assets.wall;
    if (y == 0)
        img = game.assets.wall_t;
    else if (y == game.map_h - 1)
        img = game.assets.wall_b;
        
    if (x == 0)
        img = game.assets.wall_l;
    else if (x == game.map_w - 1)
        img = game.assets.wall_r;
        
    if (x == 0 && y == 0)
        img = game.assets.wall_tl;
    else if (x == (game.map_w - 1) && y == 0)
        img = game.assets.wall_tr;
    else if (x == 0 && y == game.map_h - 1)
        img = game.assets.wall_bl;
    else if (x == (game.map_w - 1) && y == game.map_h - 1)
        img = game.assets.wall_br;
    return (img);
}
