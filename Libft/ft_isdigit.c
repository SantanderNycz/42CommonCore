/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:19 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:15 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
    printf("isdigit('5'): %d\n", isdigit('5'));
    printf("ft_isdigit('5'): %d\n", ft_isdigit('5'));
	
	return (0);
}*/