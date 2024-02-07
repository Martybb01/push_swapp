/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/07 23:23:27 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo to sort three numbers

void sort_three(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value < (*stack_a)->next->next->value)
		nodes_swap(*stack_a, "sa");
	else if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			nodes_swap(*stack_a, "sa");
			nodes_reverse_rotate(stack_a, "rra");
		}
		else
			nodes_rotate(stack_a, "ra");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
	{
		nodes_reverse_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value < (*stack_a)->next->next->value)
	{
		nodes_swap(*stack_a, "sa");
		nodes_rotate(stack_a, "ra");
	}
}

// find the best move to push a number from stack b to stack a

// ft_printf("stack a value %d\n", (*stack_a)->value);
// ft_printf("stack a prev value %d\n", (*stack_a)->prev->value);
// ft_printf("stack a next value %d\n", (*stack_a)->next->value);
// ft_printf("stack a prev prev value %d\n", (*stack_a)->prev->prev->value);
// ft_printf("stack a next next value %d\n", (*stack_a)->next->next->value);
// ft_printf("°°°°°°°°°°°°°°°°°°°\n");
// ft_printf("stack b value %d\n", (*stack_b)->value);
// ft_printf("stack b prev value %d\n", (*stack_b)->prev->value);
// ft_printf("stack b next value %d\n", (*stack_b)->next->value);

void sort_small(t_stack **stack_a, t_stack **stack_b, int len)
{
	int i;

	i = 0;
	while (i < len - 3)
	{
		node_push(stack_a, stack_b, "pb");
		i++;
	}
	sort_three(stack_a);

	if (len == 4)
	{
		node_push(stack_b, stack_a, "pa");
		nodes_rotate(stack_a, "ra");
	}
	else if (len == 5)
	{
		nodes_rotate(stack_a, "ra");
		nodes_rotate(stack_a, "ra");
		node_push(stack_b, stack_a, "pa");
		nodes_reverse_rotate(stack_a, "rra");
		nodes_reverse_rotate(stack_a, "rra");
		node_push(stack_b, stack_a, "pa");
		nodes_rotate(stack_a, "ra");
	}
}

void sort_under_five(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 1)
		return;
	else if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			nodes_swap(*stack_a, "sa");
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len > 3)
		sort_small(stack_a, stack_b, len);
}
