/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:35:53 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/02 18:10:24 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_enclosure(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
        if (map[0][i] != '1' || map[height - 1][i] != '1')
            return (EXIT_FAILURE);
        i++;
	}
    while (i < height)
	{
        if (map[i][0] != '1' || map[i][width - 1] != '1')
            return (EXIT_FAILURE);
        i++;
	}
	return (EXIT_SUCCESS);
}

int     check_integrity(char **map, int height, int width)
{
    int     i;

    i = 0;
    while (i < height)
    {
        if ((int)ft_strlen(map[i]) != width)
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}

int check_charactere(char **map, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
                return (EXIT_FAILURE);
            i++;
        }
    }
    return (EXIT_SUCCESS);
}

int     check_filename(char *filename)
{
    int     i;

    i = 0;
    while (filename[i])
        i++;
    i--;
    if (i < 4)
        return (EXIT_FAILURE);
    if (filename[i] != 'r' || filename[i - 1] != 'e' || filename[i - 2] != 'b' || filename[i - 3] != '.')
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int     check_map(t_game *game, char *filename)
{
    game->map = get_map(filename, &game->map_h, &game->map_w); /*retorna as linhas do mapa*/
    if (!game->map)
        return (ft_printf_e(ER_NOMAP), close_program(game));

    game->map_h = count_lines(game->map);
    game->map_w = ft_strlen(game->map[0]);
    
    if (check_charactere(game->map, game->map_h, game->map_w))
        return (ft_printf_e(ER_MAPCHAR), close_program(game));
    if (nb_occurrence(game->map, 'P') != 1)
        return (ft_printf_e(ER_NOSTART), close_program(game));
    if (nb_occurrence(game->map, 'E') != 1)
        return (ft_printf_e(ER_NOEND), close_program(game));
    if (nb_occurrence(game->map, 'C') < 1)
        return (ft_printf_e(ER_NOCOL), close_program(game));
    if (check_enclosure(game->map, game->map_h, game->map_w))
        return (ft_printf_e(ER_WALL), close_program(game));
    if (check_integrity(game->map, game->map_h, game->map_w))
        return (ft_printf_e(ER_MAPLEN), close_program(game));
    if (check_map_can_be_solved(game->map, game))
        return (ft_printf_e(ER_RESOLVE), close_program(game));
    return (0);
}