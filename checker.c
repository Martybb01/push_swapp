/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:02:32 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/27 12:11:30 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nodes_rotate_bonus(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag)
	{
		nodes_reverse_rotate(stack_a, NULL);
		nodes_reverse_rotate(stack_b, NULL);
	}
	else
	{
		nodes_rotate(stack_a, NULL);
		nodes_rotate(stack_b, NULL);
	}
}

int	check_operations(t_stack **stack_a, t_stack **stack_b, char *str)
{
	t_stack	**tmp;

	tmp = stack_b;
	if (ft_strchr(str, 'a'))
		tmp = stack_a;
	if (!ft_strncmp(str, "sa\n", 3) || !ft_strncmp(str, "sb\n", 3))
		nodes_swap(*tmp, NULL);
	else if (!ft_strncmp(str, "ss\n", 3))
		nodes_double_swap(*stack_a, *stack_b);
	else if (!ft_strncmp(str, "pa\n", 3))
		node_push(stack_b, stack_a, NULL);
	else if (!ft_strncmp(str, "pb\n", 3))
		node_push(stack_a, stack_b, NULL);
	else if (!ft_strncmp(str, "ra\n", 3) || !ft_strncmp(str, "rb\n", 3))
		nodes_rotate(tmp, NULL);
	else if (!ft_strncmp(str, "rr\n", 3))
		nodes_rotate_bonus(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "rrb\n", 4))
		nodes_reverse_rotate(tmp, NULL);
	else if (!ft_strncmp(str, "rrr\n", 4))
		nodes_rotate_bonus(stack_a, stack_b, 1);
	else
		return (free(str), 0);
	return (1);
}

void	print_result(t_stack **stack_a, t_stack **stack_b)
{
	if (check_if_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	handle_input(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	if (ac < 2)
		return (0);
	*stack_a = checker_input(ac, av);
	*stack_b = NULL;
	if (!*stack_a)
	{
		ft_free_all(*stack_a, *stack_b, NULL, NULL);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*output;

	stack_a = NULL;
	stack_b = NULL;
	if (!handle_input(ac, av, &stack_a, &stack_b))
		return (0);
	output = get_next_line(STDIN_FILENO);
	while (output != NULL)
	{
		if (output[0] == '\n' || !output)
			break ;
		if (!check_operations(&stack_a, &stack_b, output))
		{
			ft_free_all(stack_a, stack_b, NULL, NULL);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		free(output);
		output = get_next_line(STDIN_FILENO);
	}
	print_result(&stack_a, &stack_b);
	ft_free_all(stack_a, stack_b, output, NULL);
	return (0);
}
