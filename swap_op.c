/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:29:53 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/03 18:45:32 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nodes_swap(t_stack *stack, char *str)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	if (str)
	{
		ft_printf("%s\n", str);
	}
}

void	nodes_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	nodes_swap(stack_a, NULL);
	nodes_swap(stack_b, NULL);
	ft_printf("ss\n");
}

void	swap_and_rotate(t_stack **stack)
{
	nodes_swap(*stack, "sa");
	nodes_rotate(stack, "ra");
}

void	swap_and_reverse_rotate(t_stack **stack)
{
	nodes_swap(*stack, "sa");
	nodes_reverse_rotate(stack, "rra");
}
