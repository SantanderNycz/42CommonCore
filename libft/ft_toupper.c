/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:52:03 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:29 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int		main(void)
{
    printf("tolower('D'): %c\n", tolower('D'));
    printf("ft_tolower('D'): %c\n", ft_tolower('D'));

	return (0);
}
*/