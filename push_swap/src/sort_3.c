/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 20:12:24 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/31 20:20:55 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_min_first(t_list **a, int next_min)
{
	if ((*a)->next->index != next_min)
	{
		ra(a);
		sa(a);
		rra(a);
	}
}

static void	case_next_min_first(t_list **a, int min)
{
	if ((*a)->next->index == min)
		sa(a);
	else
		rra(a);
}

static void	case_max_first(t_list **a, int min)
{
	if ((*a)->next->index == min)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min)
		case_min_first(stack_a, next_min);
	else if (head->index == next_min)
		case_next_min_first(stack_a, min);
	else
		case_max_first(stack_a, min);
}
