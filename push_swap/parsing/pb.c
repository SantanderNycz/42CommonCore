/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:37:54 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:54 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pb(t_stack *a, t_stack *b)
{
	t_node		*tmp;

	if (!a || !a->top)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;

	write(1, "pb\n", 3);
}