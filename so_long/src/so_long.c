/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:13:25 by lsantand          #+#    #+#             */
/*   Updated: 2025/08/12 17:29:15 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int     close_program(t_game *game)
{
    if (game->game_state == 1 || game->game_state == 2)
        free(game->map);
    if (game->game_state == 3)
    {
        free(game->map);
        close_img(game);
        close_img_wall(game);
        if (game->mlx)
            mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if (game->game_state == 4)
    {
        free(game->map);
        close_img(game);
        close_img_wall(game);
        mlx_destroy_window(game->mlx, game->mlx_win);
        if (game->mlx)
            mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
    return (0);
}

int     key_press(int keycode, t_game *game)
{
    if (keycode == 65307)
        close_program(game);
    if (keycode == 119 || keycode == 65362 || keycode == 32)
        move_check(game, 't');
    if (keycode == 115 || keycode == 65364 || keycode == 65505)
        move_check(game, 'b');
    if (keycode == 97 || keycode == 65361)
        move_check(game, 'l');
    if (keycode == 100 || keycode == 65363)
        move_check(game, 'r');
    return (0);
}

void    check_event(t_game *game)
{
    mlx_hook(game->mlx_win, 17, 1L << 17, close_program, game);
    mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
}

int     main(int ac, char **av)
{
    t_game  game;
    
    ft_memset(&game, 0, sizeof(t_game));
    game.game_state = 0;
    if (ac != 2)
        return (close_program(&game), 1);
    check_map(&game, av[1]);
    game.collect = nb_occurrence(game.map, 'C');
    game.game_state = 3;
    game.mlx = mlx_init();
    if (!game.mlx)
        return (close_program(&game), 1);
    game.player_pos = find_index(game.map, 'P');
    open_imgs(game.mlx, &game);
    game.game_state = 4;
    game.mlx_win = mlx_new_window(game.mlx, game.map_w * 96, game.map_h * 96, "So long");
    if (!game.mlx_win)
        return (close_program(&game), 1);
    fill_win(game);
    check_event(&game);
    mlx_loop(game.mlx);
}