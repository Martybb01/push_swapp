/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:02:32 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/25 00:32:47 by marboccu         ###   ########.fr       */
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

char	*check_operations(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		nodes_swap(*stack_a, "sa");
	else if (!ft_strcmp(str, "sb\n"))
		nodes_swap(*stack_b, "sb");
	else if (!ft_strcmp(str, "ss\n"))
		nodes_double_swap(*stack_a, *stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		node_push(stack_b, stack_a, "pa");
	else if (!ft_strcmp(str, "pb\n"))
		node_push(stack_a, stack_b, "pb");
	else if (!ft_strcmp(str, "ra\n"))
		nodes_rotate(stack_a, "ra");
	else if (!ft_strcmp(str, "rb\n"))
		nodes_rotate(stack_b, "rb");
	else if (!ft_strcmp(str, "rr\n"))
		nodes_double_rotate(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		nodes_reverse_rotate(stack_a, "rra");
	else if (!ft_strcmp(str, "rrb\n"))
		nodes_reverse_rotate(stack_b, "rrb");
	else if (!ft_strcmp(str, "rrr\n"))
		nodes_double_reverse_rotate(stack_a, stack_b);
	else
	{
		free(str);
		ft_error();
	}
	return (get_next_line(STDIN_FILENO));
}

void	validity_checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (line && line[i] != '\n')
	{
		tmp = line;
		line = check_operations(stack_a, stack_b, line);
		free(tmp);
	}
	free(line);
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
	line = " ";
	while (line)
	{
		line = get_next_line(STDIN_FILENO);
		validity_checker(&stack_a, &stack_b, line);
	}
	if (check_if_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
