/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:17:04 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/28 22:25:28 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void node_push(t_stack **stack_src, t_stack **stack_dst, char *str)
{
	t_stack *temp;
	t_stack *temp2;

	if (!*stack_src || !stack_dst)
		return;

	temp = *stack_src;
	temp2 = *stack_dst;

	*stack_src = temp->next;
	*stack_dst = temp2->next;

	temp->next = *stack_dst;
	temp2->next = *stack_src;

	*stack_dst = temp;
	*stack_src = temp2;

	if (str)
	{
		ft_printf("%s\n", str);
	}
}
