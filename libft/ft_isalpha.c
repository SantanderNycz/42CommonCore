/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:13 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:04 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main (void)
{
    printf("isalpha('A'): %d\n", isalpha('A'));
    printf("ft_isalpha('A'): %d\n", ft_isalpha('A'));
	
	return (0);
}*/
