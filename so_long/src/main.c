/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:26:14 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 19:53:09 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "so_long.h" // seu header com t_game, assets, etc.

#define TILE_SIZE 96

int handle_close(t_game *game)
{
    // Função para fechar a janela
    mlx_destroy_window(game->mlx, game->mlx_win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free_map(game->map); // libera mapa alocado
    exit(0);
    return (0);
}

int handle_key(int keycode, t_game *game)
{
    // Aqui você processa movimentos do player
    if (keycode == 65307) // ESC
        return handle_close(game);

    // Exemplo: chamar move_check
    if (keycode == 'w') move_check(game, 't');
    if (keycode == 's') move_check(game, 'b');
    if (keycode == 'a') move_check(game, 'l');
    if (keycode == 'd') move_check(game, 'r');

    return (0);
}

int main(void)
{
    t_game game;

    // Inicialização
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);

    // Carregar mapa, assets, etc.
    if (check_map(&game, "maps/map.reb"))
        return (1);

    game.mlx_win = mlx_new_window(game.mlx, game.map_w * TILE_SIZE, game.map_h * TILE_SIZE, "so_long");
    if (!game.mlx_win)
    {
        mlx_destroy_display(game.mlx);
        free(game.mlx);
        return (1);
    }

    fill_win(game);

    mlx_key_hook(game.mlx_win, handle_key, &game);
    mlx_hook(game.mlx_win, 17, 0, handle_close, &game); // fechar com X

    // Loop principal
    mlx_loop(game.mlx);

    return (0);
}
