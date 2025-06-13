/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:22:55 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 18:22:55 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *new_node(int value)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

//para empilhar no topo da stack A
void    push_top(t_stack *stack, int value)
{
    t_node  *node;

    node =new_node(value);
    if (!node)
        return ; // ou lida com erro
    node->next = stack->top;
    stack->top = node;
}

//Pra manter a ordem correta, o último número da entrada deve ser empilhado primeiro 
void    fill_stack_a(t_stack *a, int *indexed_array, int size)
{
    int     i;

    i = size - 1;
    while (i >= 0)
    {
        push_top(a, indexed_array[i]);
        i--;
    }
}

int		is_sorted(t_stack *a)
{
	t_node		*node;

	if (!a || !a->top)
		return (1); //pilha vazia é considerada ordenada
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}