/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:37:49 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:49 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sa(t_stack *a)
{
	t_node		*first;
	t_node		*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;

	first->next = second->next;
	second->next = first;
	a->top = second;
	
	write(1, "sa\n", 3);
}