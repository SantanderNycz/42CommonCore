/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:51:10 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/19 17:08:56 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char i);

int	ft_isdigit(int i);

int	ft_isalnum(char i)
{
	if (ft_isalpha(i) || ft_isdigit(i))
		return (i);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main (void)
{
    printf("isalnum('G'): %d\n", isalnum('G'));
    printf("ft_isalnum('G'): %d\n", ft_isalnum('G'));
	
	return (0);
}*/
