/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:28:06 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/08 22:28:07 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	slen;
	int	start;
	int	end;

	slen = ft_strlen(s1);
	start = -1;
	end = slen;
	while (++start < slen && s1[start])
		if (ft_strchr(set, s1[start]) == 0)
			break ;
	while (--end < slen && s1[end] && end != 0)
		if (ft_strchr(set, s1[end]) == 0)
			break ;
	return (ft_substr(s1, start, (end - start + 1)));
}
