/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:03:19 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/10 11:52:02 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
		if (str[i] == (char)c)
			res = ((char *)&str[i]);
		i++;
	if (str[i] == c)
		res = ((char *)&str[i]);
	return (res);
}
