/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:12 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:12:04 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
    int *arr_std = (int *)calloc(4, sizeof(int));
    int *arr_ft = (int *)ft_calloc(4, sizeof(int));
    printf("calloc: %d %d %d %d\n", arr_std[0], arr_std[1], arr_std[2], arr_std[3]);
    printf("ft_calloc: %d %d %d %d\n\n", arr_ft[0], arr_ft[1], arr_ft[2], arr_ft[3]);
    free(arr_std);
    free(arr_ft);
	
	return (0);
}*/