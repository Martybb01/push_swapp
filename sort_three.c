/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/06 17:34:49 by marboccu         ###   ########.fr       */
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

// calculate distance of every number from top position in stack b
void calculate_distance(t_stack **stack_b, int len)
{
	t_stack *temp;
	int i;
	int value;

	i = 0;
	temp = *stack_b;
	while (i < len)
	{
		temp->curr_pos = i;
		value = temp->value;
		if (temp->curr_pos <= len / 2)
			value = temp->curr_pos;
		else
			value = temp->curr_pos - len;
		ft_printf("L'elemento %d ha valore %d e distanza %d\n", i + 1, temp->value, value);
		temp = temp->next;
		i++;
	}
}

// algo to sort 5 numbers
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int len;
	int *temp;

	i = 0;
	len = ft_stack_size(*stack_a);
	temp = malloc(sizeof(int) * ft_stack_size(*stack_b));
	while (i < len - 3)
	{
		node_push(stack_a, stack_b, "pb");
		i++;
	}
	sort_three(stack_a);
	calculate_distance(stack_b, ft_stack_size(*stack_b));
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
		sort_five(stack_a, stack_b);
}
