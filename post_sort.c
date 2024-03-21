/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/21 16:50:53 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sequence	*find_sequence(t_stack *stack)
{
	int			i;
	t_sequence	*seq;
	t_stack		*current;

	i = 0;
	seq = malloc(sizeof(t_sequence));
	current = stack;
	while (current && current->next)
	{
		if (current->value < current->next->value)
		{
			if (seq->start_idx == -1)
			{
				seq->start_idx = i;
				seq->final_idx = i + 1;
			}
			else
				seq->final_idx = i + 1;
		}
		else
		{
			if (seq->start_idx != -1)
				break ;
		}
		current = current->next;
		i++;
	}
	return (seq);
}

void	post_optimization(t_stack **stack_a, t_stack **stack_b)
{
	t_sequence	*seq;

	(void)stack_b;
	seq = find_sequence(*stack_a);
	if (seq->start_idx != -1)
	{
		ft_printf("start: %d, final: %d\n", seq->start_idx, seq->final_idx);
		ft_printf("start: %d, final: %d\n", seq->start_idx, seq->final_idx);
	}
}
