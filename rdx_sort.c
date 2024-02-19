/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:17 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/19 14:55:40 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	max_num;
	int	i;
	int	j;
	int	max_bits;

	len = ft_stack_size(*stack_a);
	max_num = len - 1;
	max_bits = 0;
	quicksort_stack(stack_a, 0, len - 1);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->value >> i) & 1) == 1)
			{
				if (is_closer_to_top(*stack_a, (*stack_a)->value, len) == 1)
				{
					nodes_rotate(stack_a, "ra");
				}
				else
				{
					nodes_reverse_rotate(stack_a, "rra");
				}
			}
			else
				node_push(stack_a, stack_b, "pb");
			++j;
		}
		i++;
		while (*stack_b)
			node_push(stack_b, stack_a, "pa");
	}
}
