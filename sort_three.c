/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:53:30 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/03 18:55:24 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_correct(t_stack **stack, int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
			swap_and_reverse_rotate(stack);
		else
			nodes_rotate(stack, "ra");
	}
	else if (first < second && first > third)
		nodes_reverse_rotate(stack, "rra");
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third)
		nodes_swap(*stack_a, "sa");
	else if ((first > second && first > third) || (first < second
			&& first > third))
		rotate_until_correct(stack_a, first, second, third);
	else if (first > second && second > third)
		swap_and_reverse_rotate(stack_a);
	else if (first < second && first < third)
		swap_and_rotate(stack_a);
}
