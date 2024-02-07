/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/07 21:01:53 by marboccu         ###   ########.fr       */
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
	// int *temp;
	t_stack *max_a;
	t_stack *min_a;
	t_stack *max_b;
	t_stack *min_b;

	i = 0;
	len = ft_stack_size(*stack_a);
	// temp = malloc(sizeof(int) * ft_stack_size(*stack_b));
	while (i < len - 3)
	{
		node_push(stack_a, stack_b, "pb");
		i++;
	}
	sort_three(stack_a);
	max_a = stack_max_value(*stack_a);
	ft_printf("last of stack a %d\n", max_a->value);
	min_a = stack_min_value(*stack_a);
	ft_printf("first of stack a %d\n", min_a->value);
	max_b = stack_max_value(*stack_b);
	ft_printf("last of stack b %d\n", max_b->value);
	min_b = stack_min_value(*stack_b);
	ft_printf("first of stack b %d\n", min_b->value);
	if (max_b->value < max_a->value)
		node_push(stack_a, stack_b, "pa");
	else if (min_b->value > min_a->value)
		node_push(stack_a, stack_b, "pa");

	// while stack_b is not empty
	while (*stack_b != NULL && max_b < min_a)
	{
		max_b = stack_max_value(*stack_b);
		min_a = stack_min_value(*stack_a);
		if (max_b->value < min_a->value)
		{
			node_push(stack_a, stack_b, "pa");
			break;
		}

		// node_push(stack_b, stack_a, "pa");
		// {
		// 	nodes_rotate(stack_b, "rb");
		// 	max_b = stack_max_value(*stack_b);
		// 	ft_printf("last of stack b %d\n", max_b->value);
		// 	// break;
		// }
		// calculate_distance(stack_b, ft_stack_size(*stack_b));
		// max_b = stack_max_value(*stack_b);
		// min_b = stack_min_value(*stack_b);
		// if (max_b->curr_pos == 0 || min_b->curr_pos == 0)
		// {
		// 	node_push(stack_a, stack_b, "pa");
		// 	// continue;
		// }
		// if (max_b->curr_pos < 0)
		// 	nodes_reverse_rotate(stack_b, "rrb");
		// else
		// 	nodes_rotate(stack_b, "rb");
		// max_b = stack_max_value(*stack_b);
	}

	while (stack_b != NULL)
	{
		node_push(stack_b, stack_a, "pa");
	}
	//  calculate_distance(stack_b, ft_stack_size(*stack_b));
	//  max = stack_max_value(*stack_a);
	//  ft_printf("il valore massimo è %d\n", max->value);
	//  min = stack_min_value(*stack_a);
	//  ft_printf("il valore minimo è %d\n", min->value);
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
