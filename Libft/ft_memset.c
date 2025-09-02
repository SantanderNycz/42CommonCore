/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:16:07 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/15 14:51:37 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *str, int size, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)str;
	while (len--)
		*temp++ = (unsigned char)size;
	return (str);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char buffer1[10];
    char buffer2[10];
    memset(buffer1, 'A', 5);
    ft_memset(buffer2, 'A', 5);
    printf("memset: %.5s\n", buffer1);
    printf("ft_memset: %.5s\n\n", buffer2);
    
	return (0);
}
*/