/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:44 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:10:18 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
    printf("strlen('Hello'): %lu\n", strlen("Hello"));
    printf("ft_strlen('Hello'): %lu\n", ft_strlen("Hello"));
	
	return (0);
}
*/