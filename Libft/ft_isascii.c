/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:16 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:10 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int i)
{
	return (i >= 0 && i <= 127);
}

/*
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
    printf("isascii(127): %d\n", isascii(127));
    printf("ft_isascii(127): %d\n", ft_isascii(127));
    
	return (0);
}*/