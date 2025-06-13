/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:37:56 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:56 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pa(t_stack *a, t_stack *b)
{
	t_node		*tmp;

	if (!b || !b->top)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;

	write(1, "pa\n", 3);
}