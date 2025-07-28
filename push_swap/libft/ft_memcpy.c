/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:44:28 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/06 18:44:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_val;
	unsigned char		*src_val;
	size_t				i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dest_val = (unsigned char *)dest;
	src_val = (unsigned char *)src;
	while (i < n)
	{
		dest_val[i] = src_val[i];
		i++;
	}
	return (dest);
}
