/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:17 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/18 11:40:54 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		min_num;
	int		max_num;
	t_stack	*current;
	int		max_bits;
	int		count_0;
	int		count_1;

	min_num = INT_MAX;
	max_num = INT_MIN;
	// Find the minimum and maximum values in the stack
	current = *stack_a;
	while (current)
	{
		if (current->value < min_num)
		{
			min_num = current->value;
		}
		if (current->value > max_num)
		{
			max_num = current->value;
		}
		current = current->next;
	}
	// Calculate the maximum number of bits required
	max_bits = 0;
	if (max_num >= 0)
	{
		while (max_num > 0)
		{
			++max_bits;
			max_num >>= 1;
		}
	}
	else
	{
		max_bits = sizeof(int) * 8;
	}
	// Sort the stack using radix sort
	for (int i = 0; i < max_bits; ++i)
	{
		count_0 = 0;
		count_1 = 0;
		current = *stack_a;
		while (current)
		{
			if ((current->value >> i) & 1)
			{
				++count_1;
			}
			else
			{
				++count_0;
			}
			current = current->next;
		}
		// Move the elements to stack_b based on the bit value
		for (int j = 0; j < count_0; ++j)
		{
			if (((*stack_a)->value >> i) & 1)
			{
				nodes_rotate(stack_a, "ra");
			}
			else
			{
				node_push(stack_a, stack_b, "pb");
			}
		}
		// Move the elements back to stack_a
		for (int j = 0; j < count_1; ++j)
		{
			if (((*stack_b)->value >> i) & 1)
			{
				node_push(stack_b, stack_a, "pa");
			}
			else
			{
				nodes_reverse_rotate(stack_a, "rra");
			}
		}
	}
	while (*stack_b)
	{
		node_push(stack_b, stack_a, "pa");
	}
}

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		min_num;
// 	int		max_num;
// 	int		max_bits;
// 	t_stack	*current;
// 	int		count_0;
// 	int		count_1;

// 	// int		len;
// 	// len = ft_stack_size(*stack_a);
// 	min_num = INT_MAX;
// 	max_num = INT_MIN;
// 	max_bits = 0;
// 	// Find the minimum and maximum values in the stack
// 	current = *stack_a;
// 	while (current)
// 	{
// 		if (current->value < min_num)
// 		{
// 			min_num = current->value;
// 		}
// 		if (current->value > max_num)
// 		{
// 			max_num = current->value;
// 		}
// 		current = current->next;
// 	}
// 	// Subtract the minimum value from each element to make them non-negative
// 	current = *stack_a;
// 	while (current)
// 	{
// 		current->value -= min_num;
// 		current = current->next;
// 	}
// 	// Calculate the maximum number and the number of bits required
// 	while (max_num > 0)
// 	{
// 		++max_bits;
// 		max_num >>= 1;
// 	}
// 	for (int i = 0; i < max_bits; ++i)
// 	{
// 		count_0 = 0;
// 		count_1 = 0;
// 		current = *stack_a;
// 		while (current)
// 		{
// 			if ((current->value >> i) & 1)
// 			{
// 				++count_1;
// 			}
// 			else
// 			{
// 				++count_0;
// 			}
// 			current = current->next;
// 		}
// 		// Move the elements to the appropriate stack
// 		for (int j = 0; j < count_0; ++j)
// 		{
// 			if (((*stack_a)->value >> i) & 1)
// 			{
// 				nodes_reverse_rotate(stack_a, "rra");
// 			}
// 			else
// 			{
// 				node_push(stack_a, stack_b, "pb");
// 			}
// 		}
// 		for (int j = 0; j < count_1; ++j)
// 		{
// 			if (((*stack_a)->value >> i) & 1)
// 			{
// 				nodes_rotate(stack_a, "ra");
// 			}
// 			else
// 			{
// 				node_push(stack_a, stack_b, "pb");
// 			}
// 		}
// 		// Move the elements back to stack_a
// 		while (*stack_b)
// 		{
// 			node_push(stack_b, stack_a, "pa");
// 		}
// 	}
// }
// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		len;
// 	int		max_num;
// 	int		max_bits;
// 	int		count_0;
// 	int		count_1;
// 	t_stack	*current;
// 	int		mapped_value;

// 	len = ft_stack_size(*stack_a);
// 	max_num = len - 1;
// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
// 	{
// 		++max_bits;
// 	}
// 	quicksort_stack(stack_a, 0, len - 1);
// 	for (int i = 0; i < max_bits; ++i)
// 	{
// 		count_0 = 0;
// 		count_1 = 0;
// 		current = *stack_a;
// 		while (current)
// 		{
// 			mapped_value = (current->value >> i) & 1;
// 			if ((mapped_value == 0 && current->value >= 0) || (mapped_value == 1
// 					&& current->value < 0))
// 			{
// 				++count_0;
// 			}
// 			else
// 			{
// 				++count_1;
// 			}
// 			current = current->next;
// 		}
// 		// Move the elements to the appropriate stack
// 		for (int j = 0; j < count_0; ++j)
// 		{
// 			if (((*stack_a)->value >> i) & 1)
// 			{
// 				nodes_reverse_rotate(stack_a, "rra");
// 			}
// 			else
// 			{
// 				node_push(stack_a, stack_b, "pb");
// 			}
// 		}
// 		for (int j = 0; j < count_1; ++j)
// 		{
// 			if (((*stack_a)->value >> i) & 1)
// 			{
// 				nodes_rotate(stack_a, "ra");
// 			}
// 			else
// 			{
// 				node_push(stack_a, stack_b, "pb");
// 			}
// 		}
// 		// Move the elements back to stack_a
// 		while (*stack_b)
// 		{
// 			node_push(stack_b, stack_a, "pa");
// 		}
// 	}
// }

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		len;
// 	int		max_num;
// 	int		max_bits;
// 	int		count_0;
// 	int		count_1;
// 	t_stack	*current;
// 	int		i;

// 	len = ft_stack_size(*stack_a);
// 	max_num = len - 1;
// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
// 		++max_bits;
// 	quicksort_stack(stack_a, 0, len - 1);
// 	while (max_bits > 0)
// 	{
// 		count_0 = 0;
// 		count_1 = 0;
// 		current = *stack_a;
// 		while (current)
// 		{
// 			if ((current->value >> (max_bits - 1)) & 1)
// 				++count_1;
// 			else
// 				++count_0;
// 			current = current->next;
// 		}
// 		i = 0;
// 		while (i < count_0)
// 		{
// 			node_push(stack_a, stack_b, "pb");
// 			++i;
// 		}
// 		i = 0;
// 		while (i < count_1)
// 		{
// 			if (is_on_top(*stack_a, (*stack_a)->value) == 1)
// 				nodes_rotate(stack_a, "ra");
// 			else
// 				nodes_reverse_rotate(stack_a, "rra");
// 			node_push(stack_a, stack_b, "pb");
// 			++i;
// 		}
// 		--max_bits;
// 		while (*stack_b)
// 			node_push(stack_b, stack_a, "pa");
// 	}
// }

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	len;
// 	int	max_num;
// 	int	i;
// 	int	j;
// 	int	max_bits;

// 	len = ft_stack_size(*stack_a);
// 	max_num = len - 1;
// 	max_bits = 0;
// 	quicksort_stack(stack_a, 0, len - 1);
// 	while ((max_num >> max_bits) != 0)
// 		++max_bits;
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if ((((*stack_a)->value >> i) & 1) == 1)
// 			{
// 				if (is_on_top(*stack_a, (*stack_a)->value) == 1)
// 				{
// 					nodes_rotate(stack_a, "ra");
// 				}
// 				else
// 				{
// 					nodes_reverse_rotate(stack_a, "rra");
// 				}
// 			}
// 			else
// 				node_push(stack_a, stack_b, "pb");
// 			++j;
// 		}
// 		i++;
// 		while (*stack_b)
// 			node_push(stack_b, stack_a, "pa");
// 	}
// }
