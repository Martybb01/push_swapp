/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:17 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/03 20:20:48 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	msd_radix_recursive(t_stack **stack_a, t_stack **stack_b, int bit_idx,
// 		int max_bits)
// {
// 	int	len;
// 	int	count_pa;
// 	int	i;

// 	if (bit_idx < 0 || bit_idx > max_bits)
// 		return ;
// 	len = ft_stack_size(*stack_a);
// 	count_pa = 0;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if ((((*stack_a)->value >> bit_idx) & 1) == 0)
// 		{
// 			node_push(stack_a, stack_b, "pb");
// 			count_pa++;
// 		}
// 		else
// 			nodes_rotate(stack_a, "ra");
// 		i++;
// 	}
// 	while (count_pa > 0)
// 	{
// 		node_push(stack_b, stack_a, "pa");
// 		count_pa--;
// 	}
// 	msd_radix_recursive(stack_a, stack_b, bit_idx - 1, max_bits);
// }

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	max_bits;
// 	int	max_num;

// 	map_values(stack_a);
// 	max_num = stack_max_value(*stack_a);
// 	ft_printf("max_num: %d\n", max_num);
// 	max_bits = 0;
// 	while ((max_num >> max_bits) != 0)
// 		++max_bits;
// 	msd_radix_recursive(stack_a, stack_b, max_bits - 1, max_bits);
// }

bool	is_small_subset(int len)
{
	return (len <= 20);
}

void	insertion_sort(t_stack **stack_a)
{
	t_stack	*key_node;
	t_stack	*compare_node;
	int		key_value;

	key_node = (*stack_a)->next;
	while (key_node != NULL)
	{
		key_value = key_node->value;
		compare_node = key_node;
		while (compare_node->prev != NULL
			&& compare_node->prev->value > key_value)
		{
			compare_node->value = compare_node->prev->value;
			compare_node = compare_node->prev;
		}
		compare_node->value = key_value;
		key_node = key_node->next;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	max_num;
	int	i;
	int	j;
	int	max_bits;
	int	count_pa;

	len = ft_stack_size(*stack_a);
	max_num = len - 1;
	max_bits = 0;
	map_values(stack_a);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		count_pa = 0;
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->value >> i) & 1) == 0)
			{
				node_push(stack_a, stack_b, "pb");
				count_pa++;
			}
			else if ((((*stack_a)->value >> i) & 1) == 1)
			{
				nodes_rotate(stack_a, "ra");
			}
			j++;
		}
		// if (is_small_subset(len))
		// {
		// 	insertion_sort(stack_a);
		// }
		while (count_pa > 0)
		{
			node_push(stack_b, stack_a, "pa");
			count_pa--;
		}
		i++;
	}
}
