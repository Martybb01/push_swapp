/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:11:48 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 14:05:26 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nodes_rotate(t_stack **stack, char *str)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = temp->next;
	last = ft_stacklast(temp);
	last->next = temp;
	temp->next = NULL;
	if (str)
	{
		ft_printf("%s\n", str);
	}
}

void	nodes_double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	nodes_rotate(stack_a, NULL);
	nodes_rotate(stack_b, NULL);
	ft_printf("rr\n");
}

void	stack_rotate_togheter(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node && *stack_a != cheapest_node->best_node)
		nodes_double_rotate(stack_a, stack_b);
	assign_index(*stack_a);
	// ft_printf("ecce\n");
	assign_index(*stack_b);
}
