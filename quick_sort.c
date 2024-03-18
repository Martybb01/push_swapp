/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:41 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 14:02:32 by marboccu         ###   ########.fr       */
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

void	fill_array_with_stack(t_stack **stack, int *array, int len)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (i < len)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
}

void	update_stack_values(t_stack **stack, int *array, int len)
{
	t_stack	*current;
	int		i;

	current = *stack;
	while (current != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (current->value == array[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	map_values(t_stack **stack_a)
{
	int	len;
	int	*temp_array;

	// ft_printf("Mapping values...\n");
	len = ft_stack_size(*stack_a);
	temp_array = malloc(sizeof(int) * len);
	if (!temp_array)
		ft_error();
	fill_array_with_stack(stack_a, temp_array, len);
	quick_sort(temp_array, 0, len - 1);
	update_stack_values(stack_a, temp_array, len);
	free(temp_array);
}
