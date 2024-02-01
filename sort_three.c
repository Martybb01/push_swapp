/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/01 16:30:07 by marboccu         ###   ########.fr       */
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
	else if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value && (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		nodes_reverse_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value && (*stack_a)->value < (*stack_a)->next->next->value)
	{
		nodes_swap(*stack_a, "sa");
		nodes_rotate(stack_a, "ra");
	}
}
void sort_under_three(t_stack **stack_a, int len)
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
}
