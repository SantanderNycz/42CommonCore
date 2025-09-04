/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:34:59 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 20:37:08 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int close_program(t_game *game)
{
    close_img(game);
    close_img_wall(game);
    if (game->mlx_win)
        mlx_destroy_window(game->mlx, game->mlx_win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if (game->map)
        free_map(game->map);
    exit(0);
}

int     key_press(int keycode, t_game *game)
{
    if (keycode == 65307)
        close_program(game);
    else if (keycode == 'w' || keycode == 'W')
        move_check(game, 'U');
    else if (keycode == 's' || keycode == 'S')
        move_check(game, 'D');
    else if (keycode == 'a' || keycode == 'A')
        move_check(game, 'L');
    else if (keycode == 'd' || keycode == 'D')
        move_check(game, 'R');
    return (0);
}

void    check_event(t_game *game)
{
    mlx_key_hook(game->mlx_win, key_press, game);
    mlx_hook(game->mlx_win, 17, 0, close_program, game);
}

int     main(int ac, char **av)
{
    t_game  game;

    if (argc != 2)
    {
        write(2, ER_NAME, ft_strlen(ER_NAME));
        return (1);
    }
    ft_memset(&game, 0, sizeof(t_game));
    if (!check_map(&game, argv[1]))
    {
        write(2, ER_NOMAP, ft_strlen(ER_NOMAP));
        return (1);
    }
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);
    game.mlx_win = mlx_new_window(game.mlx, game.map_w * TILE, game.map_h * TILE, "so_long");
    if (!game.mlx_win)
        return (1);

    if (!open_imgs(game.mlx, &game))
    {
        write(2, "Erro ao carregar imagens\n", 26);
        close_program(&game);
    }

    fill_win(game);
    check_event(&game);
    mlx_loop(game.mlx);
}
