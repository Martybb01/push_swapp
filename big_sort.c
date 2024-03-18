/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:06:48 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 15:22:53 by marboccu         ###   ########.fr       */
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
	// ft_printf("stack_size: %d\n", ft_stack_size(stack));
	center = ft_stack_size(stack) / 2;
	// ft_printf("assign_index\n");
	while (stack)
	{
		stack->final_idx = i;
		// ft_printf("value: %d, index: %d\n", stack->value, stack->final_idx);
		if (i <= center)
			stack->is_half_up = 1;
		else
			stack->is_half_up = 0;
		// ft_printf("is_half_up: %d\n", stack->is_half_up);
		stack = stack->next;
		i++;
	}
}

// every node in b gets its best/target value in a
void	find_best_biggest_smallest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_a;
	t_stack	*best_node;
	int		best_match;

	while (stack_b)
	{
		curr_a = stack_a;
		best_match = INT_MAX;
		while (curr_a)
		{
			if (curr_a->value > stack_b->value && curr_a->value < best_match)
			{
				best_match = curr_a->value;
				best_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match != INT_MAX)
		{
			stack_b->best_node = best_node;
			// ft_printf("best_biggest_smallest: %d\n",
			// stack_b->best_node->value);
		}
		else
		{
			stack_b->best_node = ft_find_min_node(&stack_a);
			// ft_printf("best_biggest_smallesttt: %d\n",
			// 	stack_b->best_node->value);
		}
		stack_b = stack_b->next;
	}
}

void	calc_push_price(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	while (stack_b)
	{
		stack_b->push_to_b_price = stack_b->final_idx;
		if (stack_b->is_half_up == 0)
			stack_b->push_to_b_price = size_b - stack_b->final_idx;
		if (stack_b->best_node->is_half_up == 0)
			stack_b->push_to_b_price += size_a - stack_b->best_node->final_idx;
		else
			stack_b->push_to_b_price += stack_b->best_node->final_idx;
		// ft_printf("push_to_b_price: %d\n", stack_b->push_to_b_price);
		stack_b = stack_b->next;
	}
}

void	set_cheapest_push(t_stack *stack_b)
{
	t_stack	*best_matching_node;
	int		best_matching_idx;

	if (!stack_b)
		return ;
	best_matching_idx = INT_MAX;
	while (stack_b)
	{
		if (stack_b->push_to_b_price < best_matching_idx)
		{
			best_matching_idx = stack_b->push_to_b_price;
			best_matching_node = stack_b;
		}
		// ft_printf("best_matching_node: %d\n", best_matching_node->value);
		stack_b = stack_b->next;
	}
	best_matching_node->cheapest_node = 1;
	// ft_printf("is cheapest_node: %d\n", best_matching_node->cheapest_node);
}

t_stack	*take_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		// ft_printf("finding cheapest node\n");
		if (stack->cheapest_node == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	post_rotation(t_stack **stack, t_stack *cheapest_node, char stack_name)
{
	char	*rotate_op;
	char	*rev_rotate_op;

	rotate_op = NULL;
	rev_rotate_op = NULL;
	// ft_printf("post_rotation\n");
	if (stack_name == 'a')
	{
		rotate_op = "ra";
		rev_rotate_op = "rra";
	}
	else if (stack_name == 'b')
	{
		rotate_op = "rb";
		rev_rotate_op = "rrb";
	}
	if (*stack != cheapest_node)
	{
		if (cheapest_node->is_half_up == 1)
		{
			while (*stack != cheapest_node)
				nodes_rotate(stack, rotate_op);
		}
		else
		{
			while (*stack != cheapest_node)
				nodes_reverse_rotate(stack, rev_rotate_op);
		}
	}
}

void	move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = take_cheapest_node(*stack_b);
	// ft_printf("taking cheaper node\n");
	// ft_printf("cheapest_node: %d\n", cheapest_node->value);
	if (cheapest_node->is_half_up == 1
		&& cheapest_node->best_node->is_half_up == 1)
	{
		// ft_printf("rotate\n");
		stack_rotate_togheter(stack_a, stack_b, cheapest_node);
	}
	else if (cheapest_node->is_half_up == 0
		&& cheapest_node->best_node->is_half_up == 0)
	{
		// ft_printf("reverse rotate\n");
		stack_rev_rotate_togheter(stack_a, stack_b, cheapest_node);
	}
	// ft_printf("post_rotation\n");
	post_rotation(stack_b, cheapest_node, 'b');
	post_rotation(stack_a, cheapest_node->best_node, 'a');
	node_push(stack_b, stack_a, "pa");
}

void	prepare_stack(t_stack *stack_a, t_stack *stack_b)
{
	assign_index(stack_a);
	assign_index(stack_b);
	find_best_biggest_smallest(stack_a, stack_b);
	calc_push_price(stack_a, stack_b);
	// ft_printf("set_cheapest_push\n");
	set_cheapest_push(stack_b);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_a_size;
	int	index;

	// t_stack	*smallest;
	map_values(stack_a);
	stack_a_size = ft_stack_size(*stack_a);
	// ft_printf("stack_sizeAA: %d\n", ft_stack_size(*stack_a));
	while (stack_a_size-- > 3)
		node_push(stack_a, stack_b, "pb");
	// ft_printf("stack_sizeBB: %d\n", ft_stack_size(*stack_b));
	sort_three(stack_a);
	// ft_printf("sort three\n");
	while (*stack_b)
	{
		prepare_stack(*stack_a, *stack_b);
		// ft_printf("Round 1\n");
		move(stack_a, stack_b);
	}
	assign_index(*stack_a);
	// smallest = ft_find_min_node(stack_a);
	index = check_index(*stack_a, stack_min_value(*stack_a));
	// ft_printf("smallest: %d\n", smallest->value);
	// ft_printf("is half up: %d\n", smallest->is_half_up);
	// if (smallest->is_half_up == 1)
	// {
	// 	while (*stack_a != smallest)
	// 		nodes_rotate(stack_a, "ra");
	// }
	// else
	// {
	// 	while (*stack_a != smallest)
	// 		nodes_reverse_rotate(stack_a, "rra");
	// }
	if (index < ft_stack_size(*stack_a) - index)
	{
		while (index > 0)
		{
			nodes_rotate(stack_a, "ra");
			index--;
		}
	}
	else
	{
		while (index < ft_stack_size(*stack_a))
		{
			nodes_reverse_rotate(stack_a, "rra");
			index++;
		}
	}
}
