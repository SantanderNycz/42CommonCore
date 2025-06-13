/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:24 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 18:26:24 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*top;
}	t_stack;

// Parsing
int		*parse_args(char **argv, int size);
int		has_duplicates(int *arr, int size);
int		ft_atoi(const char *str, int *out);

// Indexação
int		*index_array(int *original, int size);
int		*copy_array(int *arr, int size);
void	bubble_sort(int *arr, int size);
int		get_max_bits(int max_value);

// Pilhas
void	fill_stack_a(t_stack *a, int *indexed_array, int size);
int		is_sorted(t_stack *a);
void	free_stack(t_stack *stack);

// Operações
void	ra(t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	sa(t_stack *a);
int		is_empty(t_stack *stack);

// Algoritmo principal
void	radix_sort(t_stack *a, t_stack *b, int size, int max_bits);

#endif
