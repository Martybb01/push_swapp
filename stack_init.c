/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:25:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/19 20:30:07 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_new_node(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = num;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

int	check_if_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
