/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/28 12:44:17 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void ft_add_new_node(t_stack **stack, int num)
{
	t_stack *new_node;
	t_stack *last_node;

	if (!stack)
		return;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
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

void print_stack(t_stack *stack, char *str)
{
	if (str)
		ft_printf("%s:\n", str);
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

t_stack *ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
