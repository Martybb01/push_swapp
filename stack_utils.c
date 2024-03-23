/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/23 23:29:23 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min_node(t_stack **head)
{
	t_stack	*min;
	t_stack	*current;

	min = *head;
	current = *head;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

int	stack_min_value(t_stack *stack)
{
	int	min;

	if (!stack)
		return (1);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	check_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->value != value)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

void	assign_index(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->final_idx = i;
		if (i <= center)
			stack->is_half_up = 1;
		else
			stack->is_half_up = 0;
		stack = stack->next;
		i++;
	}
}

int	is_closer_to_top(t_stack *stack, int x, int len)
{
	int	distance;

	distance = 0;
	while (stack != NULL)
	{
		if (stack->value == x)
			break ;
		stack = stack->next;
		distance++;
	}
	return (distance < len / 2);
}
