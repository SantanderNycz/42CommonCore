/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:16:18 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 12:02:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*udest;
	const unsigned char	*usrc;

	if (!dest && !src)
		return (NULL);
	udest = (unsigned char *) dest;
	usrc = (const unsigned char *) src;
	if (udest < usrc)
		return (ft_memcpy(dest, src, len));
	while (len--)
		udest[len] = usrc[len];
	return (dest);
}
