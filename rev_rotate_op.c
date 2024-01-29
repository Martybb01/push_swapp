/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:42:23 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/28 22:10:33 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void nodes_reverse_rotate(t_stack **stack_head, char *str)
{
	t_stack *temp;
	t_stack *last;

	if (!*stack_head || !(*stack_head)->next)
		return;

	temp = *stack_head;

	while (temp->next->next)
		temp = temp->next;

	last = temp->next;
	temp->next = NULL;
	last->next = *stack_head;
	*stack_head = last;

	if (str)
	{
		ft_printf("%s\n", str);
	}
}

void nodes_double_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	nodes_reverse_rotate(stack_a, NULL);
	nodes_reverse_rotate(stack_b, NULL);
	ft_printf("rrr\n");
}
