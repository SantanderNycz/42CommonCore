/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:28:01 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/08 22:28:02 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	if (c == 0)
		return ((char *)(&str[i]));
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
