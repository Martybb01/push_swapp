/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:58:17 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/15 12:25:50 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	merge(int arr[], int l, int m, int r)
// {
// 	int	n1;
// 	int	n2;
// 	int	*L;
// 	int	*R;

// 	int i, j, k;
// 	n1 = m - l + 1;
// 	n2 = r - m;
// 	for (i = 0; i < n1; i++)
// 		L[i] = arr[l + i];
// 	for (j = 0; j < n2; j++)
// 		R[j] = arr[m + 1 + j];
// 	i = 0;
// 	j = 0;
// 	k = l;
// 	while (i < n1 && j < n2)
// 	{
// 		if (L[i] <= R[j])
// 		{
// 			arr[k] = L[i];
// 			i++;
// 		}
// 		else
// 		{
// 			arr[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}
// 	while (i < n1)
// 	{
// 		arr[k] = L[i];
// 		i++;
// 		k++;
// 	}
// 	while (j < n2)
// 	{
// 		arr[k] = R[j];
// 		j++;
// 		k++;
// 	}
// }

// void	mergeSort(int arr[], int l, int r)
// {
// 	int	m;

// 	if (l < r)
// 	{
// 		m = l + (r - l) / 2;
// 		mergeSort(arr, l, m);
// 		mergeSort(arr, m + 1, r);
// 		merge(arr, l, m, r);
// 	}
// }

// static int	count_bits(int num)
// {
// 	int	count;

// 	count = 1;
// 	while (num && count++)
// 	{
// 		num >>= 1;
// 	}
// 	return (count - 1);
// }

// void	radix_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	num;
// 	int	i;
// 	int	size;

// 	num = count_bits(ft_stack_size(*stack_a) - 1);
// 	i = 0;
// 	quicksort_stack(stack_a, 0, ft_stack_size(*stack_a) - 1);
// 	while (i < num)
// 	{
// 		size = ft_stack_size(*stack_a);
// 		while (size--)
// 		{
// 			if (((*stack_a)->value) & (1 << i))
// 			{
// 				if (is_closer_to_top(*stack_a, (*stack_a)->value, size))
// 					nodes_rotate(stack_a, "ra");
// 				else
// 					nodes_reverse_rotate(stack_a, "rra");
// 			}
// 			else
// 				node_push(stack_a, stack_b, "pb");
// 		}
// 		size = ft_stack_size(*stack_b) + 1;
// 		while (--size)
// 			node_push(stack_b, stack_a, "pa");
// 		i++;
// 	}
// }

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
				nodes_rotate(stack_a, "ra");
			else
				node_push(stack_a, stack_b, "pb");
			++j;
		}
		i++;
		while (*stack_b)
			node_push(stack_b, stack_a, "pa");
	}
}
