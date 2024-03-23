/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:38:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/23 14:39:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sequence	*find_sequence(t_stack *stack)
{
	int			i;
	t_sequence	*seq;
	t_stack		*current;
	int			is_next;
	int			init_start;
	int			finish_end;
	int			count;
	int			missing_nums;

	// int			in_sequence;
	i = 0;
	is_next = -1;
	seq = malloc(sizeof(t_sequence));
	if (!seq)
		return (NULL);
	seq->start_idx = -1;
	seq->final_idx = -1;
	current = stack;
	// in_sequence = 0;
	while (current != NULL)
	{
		if (is_next != -1 && current->value != is_next)
		{
			seq->start_idx = is_next;
		}
		seq->final_idx = is_next;
		is_next = current->value + 1;
		ft_printf("i: %d, value: %d\n", i, current->value);
		current = current->next;
		i++;
	}
	i = 0;
	current = stack;
	ft_printf("starttt: %d, finallll: %d\n", seq->start_idx, seq->final_idx);
	init_start = seq->start_idx;
	ft_printf("init_start: %d\n", init_start);
	finish_end = seq->final_idx;
	ft_printf("finish_end: %d\n", finish_end);
	count = 0;
	missing_nums = finish_end - init_start + 1;
	// ft_printf("missing_nums: %d\n", missing_nums);
	while (current)
	{
		// ft_printf("init_start: %d, finish_end: %d, value: %d, i: %d\n",
		// 	init_start, finish_end, current->value, i);
		if (current->value >= init_start && current->value <= finish_end)
		{
			// ft_printf("start_idx: %d\n", seq->start_idx);
			if (seq->start_idx != init_start)
				seq->start_idx = i;
			seq->final_idx = i;
			count++;
		}
		if (count == missing_nums)
			break ;
		current = current->next;
		i++;
	}
	if (seq->start_idx == -1)
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
	}
}
