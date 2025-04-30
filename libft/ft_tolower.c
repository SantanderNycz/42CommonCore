/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:52:06 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:32 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int		main(void)
{
    printf("ft_tolower('B') = %c\n", ft_tolower('B'));
	
	return (0);
}
*/