/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:29:34 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/25 15:36:46 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_u(unsigned int n)
{
	char	*str;
	int		len;
	
	str = ft_utoa(n);
	len = ft_putstr(str);
	free(str);
	return(len);
}