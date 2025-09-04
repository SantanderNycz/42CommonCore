/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:11:43 by lsantand          #+#    #+#             */
/*   Updated: 2025/09/04 23:11:44 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_printchar(char c, t_opt opt)
{
	int	cur;

	cur = 0;
	while (cur + 1 < opt.min_width)
		cur += print_char(' ');
	cur += print_char(c);
	while (cur < opt.offset)
		cur += print_char(' ');
	return (cur);
}
