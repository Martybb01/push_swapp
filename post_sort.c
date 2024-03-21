/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/21 21:16:46 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sequence	*find_sequence(t_stack *stack)
{
	int			i;
	t_sequence	*seq;
	t_stack		*current;
	int			in_sequence;

	i = 0;
	seq = malloc(sizeof(t_sequence));
	if (!seq)
		return (NULL);
	seq->start_idx = -1;
	seq->final_idx = -1;
	current = stack;
	in_sequence = 0;
	while (current)
	{
		if (current->next && current->value < current->next->value)
		{
			seq->start_idx = i;
			in_sequence = 1;
		}
		while (in_sequence)
		{
			while (current->value < current->next->value)
				i++;
			seq->final_idx = i;
			in_sequence = 0;
			// else if (in_sequence && (current->value < current->next->value
			// 		|| !current->next->next))
			// {
			// 	if (!current->next->next && in_sequence)
			// 		seq->final_idx = i + 1;
			// 	else
			// 		seq->final_idx = i;
			// 	break ;
		}
		current = current->next;
		ft_printf("i: %d\n", i);
	}
	if (seq->start_idx == -1 || seq->final_idx == -1)
	{
		free(seq);
		return (NULL);
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
