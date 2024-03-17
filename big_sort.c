/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:06:48 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/17 12:25:19 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->final_idx = i;
		ft_printf("value: %d, index: %d\n", stack->value, stack->final_idx);
		if (i <= center)
			stack->is_half_up = 1;
		else
			stack->is_half_up = 0;
		ft_printf("is_half_up: %d\n", stack->is_half_up);
		stack = stack->next;
		i++;
	}
}

/*
prepare_stack(t_stack *stack_a, t_stack *stack_b) contiene:
	assign_index(stack_a)
	assign_index(stack_b)
	find_best_node(stack_a, stack_b)
	calc_push_price(stack_a, stack_b)
	set_cheapest_push(stack_b)

*/

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	map_values(stack_a);
	while (ft_stack_size(*stack_a) > 3)
		node_push(stack_a, stack_b, "pb");
	sort_three(stack_a);
	// implementare algoritmo per b
	// while (*stack_b)
	// {
	// 	prepare_stack(*stack_a, *stack_b);
	// 	move(stack_a, stack_b);
	// }
	assign_index(*stack_a);
	smallest = ft_find_min_node(stack_a);
	ft_printf("smallest: %d\n", smallest->value);
	ft_printf("is half up: %d\n", smallest->is_half_up);
	if (smallest->is_half_up == 1)
	{
		while (*stack_a != smallest)
			nodes_rotate(stack_a, "ra");
	}
	else
	{
		while (*stack_a != smallest)
			nodes_reverse_rotate(stack_a, "rra");
	}
}
