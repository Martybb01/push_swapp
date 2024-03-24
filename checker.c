/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:02:32 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/24 17:45:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	routing(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_size(*stack_a);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			nodes_swap(*stack_a, "sa");
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len > 3 && len <= 5)
		sort_small(stack_a, stack_b, len);
	else
		big_sort(stack_a, stack_b);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	check_operations(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa"))
		nodes_swap(*stack_a, NULL);
	else if (!ft_strcmp(str, "sb"))
		nodes_swap(*stack_b, NULL);
	else if (!ft_strcmp(str, "ss"))
		nodes_double_swap(*stack_a, *stack_b);
	else if (!ft_strcmp(str, "pa"))
		node_push(stack_b, stack_a, NULL);
	else if (!ft_strcmp(str, "pb"))
		node_push(stack_a, stack_b, NULL);
	else if (!ft_strcmp(str, "ra"))
		nodes_rotate(stack_a, NULL);
	else if (!ft_strcmp(str, "rb"))
		nodes_rotate(stack_b, NULL);
	else if (!ft_strcmp(str, "rr"))
		nodes_double_rotate(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra"))
		nodes_reverse_rotate(stack_a, NULL);
	else if (!ft_strcmp(str, "rrb"))
		nodes_reverse_rotate(stack_b, NULL);
	else if (!ft_strcmp(str, "rrr"))
		nodes_double_reverse_rotate(stack_a, stack_b);
	else
	{
		free(str);
		ft_error();
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp_a;
	char	*line;
	int		size;
	t_stack	*stack_b;
	t_stack	*temp_b;

	stack_a = checker_input(ac, av);
	temp_a = stack_a;
	size = ft_stack_size(temp_a);
	stack_b = NULL;
	temp_b = stack_b;
	line = "";
	while (!line)
	{
		line = get_next_line(STDIN_FILENO);
		check_operations(&temp_a, &temp_b, line);
		free(line);
	}
	if (check_if_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		return (0);
	}
	else
		routing(&stack_a, &stack_b);
	if (check_if_sorted(temp_a) && size == ft_stack_size(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(stack_a);
	return (0);
}
