/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:16:07 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 12:15:09 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *ft_memset(void *str, int size, size_t len)
{
    unsigned char   *temp;

    temp = (unsigned char *)str;
    while (len--)
        *temp++ = (unsigned char)size;
    return (str);
}