/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/14 11:47:48 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo to sort three numbers

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
		nodes_swap(*stack_a, "sa");
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			nodes_swap(*stack_a, "sa");
			nodes_reverse_rotate(stack_a, "rra");
		}
		else
			nodes_rotate(stack_a, "ra");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value)
	{
		nodes_reverse_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		nodes_swap(*stack_a, "sa");
		nodes_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value)
	{
		nodes_swap(*stack_a, "sa");
		nodes_rotate(stack_a, "ra");
	}
}

// find the best move to push a number from stack b to stack a

// ft_printf("stack a value %d\n", (*stack_a)->value);
// ft_printf("stack a prev value %d\n", (*stack_a)->prev->value);
// ft_printf("stack a next value %d\n", (*stack_a)->next->value);
// ft_printf("stack a prev prev value %d\n", (*stack_a)->prev->prev->value);
// ft_printf("stack a next next value %d\n", (*stack_a)->next->next->value);
// ft_printf("°°°°°°°°°°°°°°°°°°°\n");
// ft_printf("stack b value %d\n", (*stack_b)->value);
// ft_printf("stack b prev value %d\n", (*stack_b)->prev->value);
// ft_printf("stack b next value %d\n", (*stack_b)->next->value);

void	ft_sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int len)
{
	int		*array;
	int		i;
	int		smallest;
	int		smallest_2nd;
	t_stack	*temp;

	i = 0;
	array = malloc(sizeof(int) * len);
	if (!array)
		ft_error();
	temp = *stack_a;
	while (i < len)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_sort_array(array, len);
	smallest = array[0];
	smallest_2nd = array[1];
	if (len == 4)
	{
		while ((*stack_a)->value != smallest)
		{
			if (is_closer_to_top(*stack_a, smallest, len))
				nodes_rotate(stack_a, "ra");
			else
				nodes_reverse_rotate(stack_a, "rra");
		}
		if (!check_if_sorted(*stack_a))
		{
			node_push(stack_a, stack_b, "pb");
			sort_three(stack_a);
			node_push(stack_b, stack_a, "pa");
		}
	}
	else
	{
		while ((*stack_a)->value != smallest)
		{
			if (is_closer_to_top(*stack_a, smallest, len))
				nodes_rotate(stack_a, "ra");
			else
				nodes_reverse_rotate(stack_a, "rra");
		}
		node_push(stack_a, stack_b, "pb");
		while ((*stack_a)->value != smallest_2nd)
		{
			if (is_closer_to_top(*stack_a, smallest_2nd, len))
				nodes_rotate(stack_a, "ra");
			else
				nodes_reverse_rotate(stack_a, "rra");
		}
		if (!check_if_sorted(*stack_a))
		{
			node_push(stack_a, stack_b, "pb");
			sort_three(stack_a);
		}
		while (*stack_b != NULL)
			node_push(stack_b, stack_a, "pa");
	}
	free(array);
}
