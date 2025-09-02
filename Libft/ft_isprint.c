/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:21 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:17 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int		main(void)
{
    printf("isprint(' '): %d\n", isprint(' '));
    printf("ft_isprint(' '): %d\n", ft_isprint(' '));
	
	return (0);
}
*/