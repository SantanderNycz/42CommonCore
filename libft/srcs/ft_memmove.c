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
	unsigned char	*udest;
	unsigned char	*usrc;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	udest = (unsigned char *) dest;
	usrc = (unsigned char *) src;
	if (udest > usrc)
		while (len-- > 0)
			udest[len] = usrc[len];
	else
	{
		while (i++ < len)
			udest[i] = usrc[i];
	}
	return (dest);
}
