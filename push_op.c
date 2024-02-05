/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:17:04 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/04 21:35:21 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void node_push(t_stack **stack_src, t_stack **stack_dst, char *str)
{
	t_stack *temp;

	if (!*stack_src)
		return;

	temp = (*stack_src)->next;

	(*stack_src)->next = *stack_dst;
	*stack_dst = *stack_src;
	*stack_src = temp;

	if (str)
	{
		ft_printf("%s\n", str);
	}
}
