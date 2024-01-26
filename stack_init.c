/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:25:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/26 17:48:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_sorted(t_stack *stack_a)
{

	if (!stack_a)
		return (0);

	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
