/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:27:45 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/08 22:27:46 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s1[i] == \
	(unsigned char)s2[i] && n > 0)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
