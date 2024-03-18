/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:19:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 12:39:35 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*init_array_from_stack(t_stack **stack, int len)
{
	int		*array;
	int		i;
	t_stack	*temp;

	i = 0;
	array = malloc(sizeof(int) * len);
	if (!array)
		ft_error();
	temp = *stack;
	while (i < len)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (array);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, int smallest)
{
	while ((*stack_a)->value != smallest)
	{
		if (is_closer_to_top(*stack_a, smallest, 4))
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

void	sort_five(t_stack **stack_a, t_stack **stack_b, int smallest,
		int smallest_2nd)
{
	while ((*stack_a)->value != smallest)
	{
		if (is_closer_to_top(*stack_a, smallest, 5))
			nodes_rotate(stack_a, "ra");
		else
			nodes_reverse_rotate(stack_a, "rra");
	}
	node_push(stack_a, stack_b, "pb");
	while ((*stack_a)->value != smallest_2nd)
	{
		if (is_closer_to_top(*stack_a, smallest_2nd, 5))
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

void	sort_small(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	*array;
	int	smallest;
	int	smallest_2nd;

	// ft_printf("ODIO\n");
	array = init_array_from_stack(stack_a, len);
	ft_sort_array(array, len);
	smallest = array[0];
	smallest_2nd = array[1];
	if (len == 4)
		sort_four(stack_a, stack_b, smallest);
	else
		sort_five(stack_a, stack_b, smallest, smallest_2nd);
	free(array);
}
