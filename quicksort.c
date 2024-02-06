/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:38:41 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/06 15:04:28 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int random_pivot(int low, int high)
{
	int pivot;

	pivot = low + rand() % (high - low);
	return (pivot);
}

void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	// int i;
	int pivot;
	(void)stack_b;
	(void)stack_a;

	if (low < high)
	{

		pivot = random_pivot(low, high);
		ft_printf("pivot: %d\n", pivot);
	}
}
