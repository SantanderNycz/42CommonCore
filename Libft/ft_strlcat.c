/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:38 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:10:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= dest_size)
		dest_len = dest_size;
	if (dest_len == dest_size)
		return (dest_size + src_len);
	if (src_len < dest_size - dest_len)
		ft_memcpy(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dest_len, src, dest_size - dest_len - 1);
		dest[dest_size - 1] = '\0';
	}
	return (dest_len + src_len);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    char cat1[20] = "Hello ";
    char cat2[20] = "Hello ";
    strlcat(cat1, "World", 20);
    ft_strlcat(cat2, "World", 20);
    printf("strlcat: %s\n", cat1);
    printf("ft_strlcat: %s\n\n", cat2);
	
	return (0);
}
*/