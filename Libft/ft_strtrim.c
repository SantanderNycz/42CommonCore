/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:10:15 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/23 13:46:06 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = ft_substr(s1, start, (end - start));
	return (res);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char *trimmed;

	trimmed = ft_strtrim("--42 Porto--", "-");
	printf("ft_strtrim: %s\n\n", trimmed);
	free(trimmed);
	
	return (0);
}
*/
