/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/27 11:52:47 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack, char *str)
// {
// 	if (str)
// 		ft_printf("%s:\n", str);
// 	while (stack)
// 	{
// 		ft_printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }

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

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp_a;
	t_stack	*stack_b;
	t_stack	*temp_b;

	stack_a = checker_input(ac, av);
	temp_a = stack_a;
	stack_b = NULL;
	temp_b = stack_b;
	if (check_if_sorted(temp_a))
	{
		ft_free_stack(temp_a);
		return (0);
	}
	else
		routing(&temp_a, &temp_b);
	ft_free_stack(temp_a);
	ft_free_stack(temp_b);
	return (0);
}
