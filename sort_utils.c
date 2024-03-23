/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:11:03 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/23 23:30:19 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			stack_b->best_node = best_node;
		else
			stack_b->best_node = ft_find_min_node(&stack_a);
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
		stack_b = stack_b->next;
	}
	best_matching_node->cheapest_node = 1;
}

void	post_rotation(t_stack **stack, t_stack *cheapest_node, char stack_name)
{
	char	*rotate_op;
	char	*rev_rotate_op;

	rotate_op = NULL;
	rev_rotate_op = NULL;
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
	while (*stack != cheapest_node)
	{
		if (cheapest_node->is_half_up == 1)
			nodes_rotate(stack, rotate_op);
		else if (cheapest_node->is_half_up == 0)
			nodes_reverse_rotate(stack, rev_rotate_op);
	}
}

void	final_rotation(t_stack **stack_a, int index, int middle)
{
	if (index < middle)
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
