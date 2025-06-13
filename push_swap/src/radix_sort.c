/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:44:50 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 00:44:50 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void    radix_sort(t_stack *a, t_stack *b, int size, int max_bits)
{
    int     i;
    int     j;
    int     num;

    i = 0;
    while (i < max_bits)
    {
        while (j < size)
        {
            num = a->top->value;
            if (((num >> 1) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (!is_empty(b))
            pa(a, b);
        i++;
    }
}
