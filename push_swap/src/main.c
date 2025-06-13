/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:35:58 by lsantand          #+#    #+#             */
/*   Updated: 2025/06/13 17:35:58 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		main(int argc, char **argv)
{
	int		*original_array;
	int		*indexed_array;
	int		size;
	int		max_bits;
	t_stack	a;
	t_stack	b;

	 if (argc < 2)
	 	return (0);

	size = argc - 1;
	a.top = NULL;
	b.top = NULL;

	original_array = parse_args(argv + 1, size);
	if (!original_array || has_duplicates(original_array, size))
	{
		write(2, "Error\n", 6);
		free(original_array);
		return (1);
	}

	fill_stack_a(&a, indexed_array, size);

	if (!is_sorted(&a))
	{
		return (free(original_array),1);
		radix_sort(&a, &b, size, max_bits);
	}

	free_stack(&a);
	free_stack(&b);
	free(original_array);
	free(indexed_array)
	return (0);
}