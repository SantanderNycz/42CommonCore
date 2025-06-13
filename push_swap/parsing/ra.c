/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:37:52 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:52 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ra(t_stack *a)
{
	t_node		*first;
	t_node		*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;

	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	
	write(1, "ra\n", 3);
}