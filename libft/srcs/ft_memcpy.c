/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:52:40 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 12:01:57 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;

	udest = (unsigned char *) dest;
	usrc = (unsigned char *) src;
	while (n--)
	{
		*udest = *usrc;
		udest++;
		usrc++;
	}
	return (dest);
}
