/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:27:36 by lsantand          #+#    #+#             */
/*   Updated: 2025/08/14 18:06:37 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int     get_map_size(t_game *game, char *filename)
{
    int     fd;
    char    c;
    int     i;
    int     rt_val;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (ft_printf_e(ER_NOMAP), close_program(game), 0);
    rt_val = 1;
    while (rt_val)
    {
        rt_val = read(fd, &c, 1);
        if (rt_val == -1)
            return (close_program(game),0);
        if (rt_val == 1)
            i++;
    }
    close (fd);
    return (i);
}

int     get_map(t_game *game, char *file)
{
    char    c;
    int     rt_val;
    int     fd;
    int     i;
    
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (ft_printf_e(ER_NOMAP), close_program(game), 0);
    i = 0;
    rt_val = 1;
    while (rt_val > 0)
    {
        rt_val = read(fd, &c, 1);
        if (rt_val == -1)
            return (close_program(game), 0);
        if (rt_val != 0)
            game->map[i] = c;
        i++;
    }
    close(fd);
    return (0);
}