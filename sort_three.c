/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:53:30 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 12:52:17 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_three(t_stack **stack_a)
// {
// 	int first, second, third;
// 	first = (*stack_a)->value;
// 	second = (*stack_a)->next->value;
// 	third = (*stack_a)->next->next->value;
// 	if (first < second && second < third) // Already sorted
// 		return ;
// 	if (first < second && first < third && second > third) // 1-3-2 scenario
// 	{
// 		nodes_swap(*stack_a, "sa");
// 		nodes_rotate(stack_a, "ra");
// 	}
// 	else if (first > second && first < third) // 2-1-3 scenario
// 		nodes_swap(*stack_a, "sa");
// 	else if (first > second && second > third) // 3-2-1 scenario
// 	{
// 		nodes_swap(*stack_a, "sa");
// 		nodes_reverse_rotate(stack_a, "rra");
// 	}
// 	else if (first > third && second < third) // 3-1-2 scenario
// 		nodes_rotate(stack_a, "ra");
// 	else // 2-3-1 scenario
// 		nodes_reverse_rotate(stack_a, "rra");
// }

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
