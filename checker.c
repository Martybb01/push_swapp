/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:02:32 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/25 18:59:13 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nodes_rev_rotate_bonus(t_stack **stack_a, t_stack **stack_b)
{
	nodes_reverse_rotate(stack_a, NULL);
	nodes_reverse_rotate(stack_b, NULL);
}

void	nodes_rotate_bonus(t_stack **stack_a, t_stack **stack_b)
{
	nodes_rotate(stack_a, NULL);
	nodes_rotate(stack_b, NULL);
}

void	check_operations(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (!str)
		ft_error_free_str(str);
	else
	{
		if (!ft_strcmp(str, "sa\n"))
			nodes_swap(stack_a, NULL);
		else if (!ft_strcmp(str, "sb\n"))
			nodes_swap(stack_b, NULL);
		else if (!ft_strcmp(str, "ss\n"))
			nodes_double_swap(stack_a, stack_b);
		else if (!ft_strcmp(str, "pa\n"))
			node_push(stack_b, stack_a, NULL);
		else if (!ft_strcmp(str, "pb\n"))
			node_push(stack_a, stack_b, NULL);
		else if (!ft_strcmp(str, "ra\n"))
			nodes_rotate(stack_a, NULL);
		else if (!ft_strcmp(str, "rb\n"))
			nodes_rotate(stack_b, NULL);
		else if (!ft_strcmp(str, "rr\n"))
			nodes_rotate_bonus(stack_a, stack_b);
		else if (!ft_strcmp(str, "rra\n"))
			nodes_reverse_rotate(stack_a, NULL);
		else if (!ft_strcmp(str, "rrb\n"))
			nodes_reverse_rotate(stack_b, NULL);
		else if (!ft_strcmp(str, "rrr\n"))
			nodes_rev_rotate_bonus(stack_a, stack_b);
		else
		{
			free(str);
			get_next_line(-42);
			ft_error();
		}
	}
}

// void	validity_checker(t_stack **stack_a, t_stack **stack_b, char *line)
// {
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	while (line && line[i] != '\n')
// 	{
// 		tmp = line;
// 		line = check_operations(stack_a, stack_b, line);
// 		free(tmp);
// 	}
// 	free(line);
// }

int	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	x;

	x = 0;
	if (ft_stack_size(stack_b) != 0)
		x = 1;
	else if (ft_stack_size(stack_a) != 1)
		x = -1;
	return (x);
}

void	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		x;
	int		flag;

	line = NULL;
	flag = 1;
	while (flag == 1 || line != NULL)
	{
		flag = 0;
		line = get_next_line(STDIN_FILENO);
		check_operations(stack_a, stack_b, line);
		if (line)
			free(line);
	}
	x = check_stacks(stack_a, stack_b);
	if (x == -1)
		ft_putstr_fd("KO\n", 1);
	else if (x == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_error();
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	char	*line;
	t_stack	*stack_b;

	stack_a = checker_input(ac, av);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_free_stack(stack_a);
		ft_error();
	}
	ft_checker(stack_a, stack_b);
	// line = "";
	// while (line)
	// {
	// 	line = get_next_line(STDIN_FILENO);
	// 	validity_checker(&stack_a, &stack_b, line);
	// 	// check_operations(&stack_a, &stack_b, line);
	// 	// free(line);
	// }
	// if (check_if_sorted(stack_a) && !stack_b)
	// 	ft_putstr_fd("OK\n", 1);
	// else
	// 	ft_putstr_fd("KO\n", 1);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
