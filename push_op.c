/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:17:04 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/18 12:32:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_push(t_stack **stack_src, t_stack **stack_dst, char *str)
{
	t_stack	*temp;

	if (!*stack_src)
		return ;
	temp = (*stack_src)->next;
	if (*stack_dst)
		(*stack_dst)->prev = *stack_src;
	(*stack_src)->next = *stack_dst;
	(*stack_src)->prev = NULL;
	*stack_dst = *stack_src;
	*stack_src = temp;
	if (temp)
		temp->prev = NULL;
	if (str)
	{
		ft_printf("%s\n", str);
	}
}
