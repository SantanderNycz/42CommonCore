/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:21:02 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 18:21:02 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     *copy_array(int *arr, int size)
{
    int     *copy;
    int     i;

    copy = malloc(sizeof(int) * size);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < size)
    {
        copy[i] = arr[i];
        i++;
    }
    return (copy);
}

void    bubble_sort(int *arr, int size)
{
    int     tmp;
    int     i;
    int     swapped;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;
        while (i < size - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
            i++;
        }
    }    
}

//retorna um array novo com os indices

int     *index_array(int *original, int size)
{
    int     *sorted;
    int     *indexed;
    int     *i;
    int     *j;

    sorted = copy_array(original, size);
    if (!sorted)
        return (NULL);
    bubble_sort(sorted, size);
    if (!indexed)
        return (free(sorted), NULL);
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (original[i] == sorted[j])
            {
                indexed[i] = j;
                break ;
            }
            j++;
        }
        i++;
    }
    free(sorted);
    return (indexed);
}

//calcular bits necessarios para o maior numero indexado
int     get_max_bits(int max_value)
{
    int     bits;

    bit = 0;
    while ((max_value >> bits) != 0)
    {
        bits++;
    }
    return (bits);
}