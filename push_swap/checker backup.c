/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker backup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:31:56 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/31 20:27:19 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_command_simple(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "sa"))
		swap(a);
	else if (!ft_strcmp(line, "sb"))
		swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp(line, "pa"))
		push(a, b);
	else if (!ft_strcmp(line, "pb"))
		push(b, a);
	else
		return (1);
	return (0);
}

static int	do_command_rotate(char *line, t_list **a, t_list **b)
{
	if (!ft_strcmp(line, "ra"))
		rotate(a);
	else if (!ft_strcmp(line, "rb"))
		rotate(b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (1);
	return (0);
}

int	do_commands(char *line, t_list **a, t_list **b)
{
	if (!line)
		return (1);
	if (!do_command_simple(line, a, b))
		return (0);
	if (!do_command_rotate(line, a, b))
		return (0);
	return (1);
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	init_stack(stack_a, argc, argv);
	while (get_next_line(0, &line))
	{
		if (do_commands(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}
