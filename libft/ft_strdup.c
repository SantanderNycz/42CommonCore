/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:28:10 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:12:23 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dest;
	size_t		len;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	ft_memcpy(dest, src, len + 1);
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    const char *original = "duplicate me";
    char *dup_std = strdup(original);
    char *dup_ft = ft_strdup(original);
    printf("strdup: %s\n", dup_std);
    printf("ft_strdup: %s\n\n", dup_ft);
    free(dup_std);
    free(dup_ft);
	
	return (0);
}
*/