/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:06:48 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/25 13:55:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*take_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest_node == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;
	t_stack	*cheapest_node_a;

	cheapest_node = take_cheapest_node(*stack_b);
	cheapest_node_a = cheapest_node->best_node;
	if (cheapest_node->is_half_up == 1
		&& cheapest_node->best_node->is_half_up == 1)
		stack_rotate_togheter(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->is_half_up == 0
		&& cheapest_node->best_node->is_half_up == 0)
		stack_rev_rotate_togheter(stack_a, stack_b, cheapest_node);
	post_rotation(stack_a, cheapest_node_a, 'a');
	post_rotation(stack_b, cheapest_node, 'b');
	node_push(stack_b, stack_a, "pa");
}

void	prepare_stack(t_stack *stack_a, t_stack *stack_b)
{
	assign_index(stack_a);
	assign_index(stack_b);
	find_best_biggest_smallest(stack_a, stack_b);
	calc_push_price(stack_a, stack_b);
	set_cheapest_push(stack_b);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_size;
	int	index;
	int	middle;

	map_values(stack_a);
	stack_a_size = ft_stack_size(*stack_a);
	while (stack_a_size-- > 3)
		node_push(stack_a, stack_b, "pb");
	if (!check_if_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		prepare_stack(*stack_a, *stack_b);
		move(stack_a, stack_b);
	}
	index = check_index(*stack_a, stack_min_value(*stack_a));
	middle = ft_stack_size(*stack_a) / 2;
	final_rotation(stack_a, index, middle);
}
