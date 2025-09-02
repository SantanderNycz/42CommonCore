/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:11:33 by lsantand          #+#    #+#             */
/*   Updated: 2025/04/21 12:32:01 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	char	str[] = "paranapiacaba!";

	printf("Antes: %s\n", str);
	ft_striteri(str, to_uppercase);
	printf("Depois: %s\n", str);

	return (0);
}
}
*/