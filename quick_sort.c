/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:41 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/19 23:13:23 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sub_partition(int *array, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high)
	{
		if (array[j] < pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int *array, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = sub_partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

int	binary_search(int *array, int num, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = num;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (array[mid] == target)
			return (mid);
		else if (array[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	quicksort_stack(t_stack **stack_a, int low, int high)
{
	int		*input;
	int		i;
	t_stack	*temp;

	input = malloc(sizeof(int) * ft_stack_size(*stack_a));
	if (!input)
		ft_error();
	i = 0;
	temp = *stack_a;
	while (i < ft_stack_size(*stack_a))
	{
		input[i] = temp->value;
		temp = temp->next;
		i++;
	}
	quick_sort(input, low, high);
	// - restituisce stack NON ordinato ma con la mappatura
	i = 0;
	temp = *stack_a;
	while (i < ft_stack_size(*stack_a))
	{
		temp->value = binary_search(input, ft_stack_size(*stack_a),
				temp->value);
		temp = temp->next;
		i++;
	}
	// - restituisce stack ordinato
	// i = 0;
	// temp = *stack_a;
	// while (i < ft_stack_size(*stack_a))
	// {
	// 	temp->value = input[i];
	// 	temp = temp->next;
	// 	i++;
	// }
	free(input);
}

// test quick_sort

// int	main(void)
// {
// 	int	array[] = {10, 7, 8, 9, 1, 5};
// 	int	n;

// 	n = sizeof(array) / sizeof(array[0]);
// 	quick_sort(array, 0, n - 1);
// 	ft_printf("Sorted array: \n");
// 	ft_print_array(array, n);
// 	return (0);
// }
