/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:29:53 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/26 17:30:01 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void nodes_swap(t_stack *stack_a, t_stack *stack_b, char *str)
{
	int tmp;

	tmp = stack_a->value;
	stack_a->value = stack_b->value;
	stack_b->value = tmp;
	if (str)
	{
		ft_printf("%s\n", str);
	}
}

void nodes_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	nodes_swap(stack_a, stack_a->next, "");
	nodes_swap(stack_b, stack_b->next, "");
}
