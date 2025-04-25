/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:28:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/23 18:39:59 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_puthex (int nbr)
{
    char *digits = "0123456789abcdef";

    ft_atoi(nbr);
    if (nbr >= 16)
        ft_puthex(nbr / 16);
    nbr = digits [nbr % 16];
    write (1, &nbr, 1);
}