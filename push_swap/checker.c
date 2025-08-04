/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantand <lsantand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:31:56 by lsantand          #+#    #+#             */
/*   Updated: 2025/07/31 20:39:42 by lsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_cmd(char *cmd, t_list **a, t_list **b)
{
	if (!ft_strcmp(cmd, "sa"))
		return (swap(a), 0);
	if (!ft_strcmp(cmd, "sb"))
		return (swap(b), 0);
	if (!ft_strcmp(cmd, "ss"))
		return (swap(a), swap(b), 0);
	if (!ft_strcmp(cmd, "pa"))
		return (push(a, b), 0);
	if (!ft_strcmp(cmd, "pb"))
		return (push(b, a), 0);
	if (!ft_strcmp(cmd, "ra"))
		return (rotate(a), 0);
	if (!ft_strcmp(cmd, "rb"))
		return (rotate(b), 0);
	if (!ft_strcmp(cmd, "rr"))
		return (rotate(a), rotate(b), 0);
	if (!ft_strcmp(cmd, "rra"))
		return (reverse_rotate(a), 0);
	if (!ft_strcmp(cmd, "rrb"))
		return (reverse_rotate(b), 0);
	if (!ft_strcmp(cmd, "rrr"))
		return (reverse_rotate(a), reverse_rotate(b), 0);
	return (1);
}

int	do_commands(char *line, t_list **a, t_list **b)
{
	if (!line)
		return (1);
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb")
		|| !ft_strcmp(line, "ss") || !ft_strcmp(line, "pa")
		|| !ft_strcmp(line, "pb") || !ft_strcmp(line, "ra")
		|| !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr")
		|| !ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb")
		|| !ft_strcmp(line, "rrr"))
		return (exec_cmd(line, a, b));
	return (1);
}

void	init_stack(t_list **stack, int argc, char **argv)
{
	char	**args;
	t_list	*new;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (argc != 2)
		i = 1;
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

void	print_checker_res(t_list **a, t_list **b)
{
	if (is_sorted(a) && !*b)
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char	*line;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	a = malloc(sizeof(t_list *));
	b = malloc(sizeof(t_list *));
	*a = NULL;
	*b = NULL;
	init_stack(a, argc, argv);
	while (get_next_line(0, &line))
	{
		if (do_commands(line, a, b))
		{
			free(line);
			ft_error("Error");
			return (1);
		}
		free(line);
	}
	print_checker_res(a, b);
	return (0);
}
