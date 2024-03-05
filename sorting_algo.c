/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:24:56 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/05 18:11:38 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
for each element in stack B:
	calculate index in stack A
	if index < stackA.size / 2:
		ra_moves = index
		rra_moves = stackA.size - index
	else:
		ra_moves = stackA.size - index
		rra_moves = index

	-Similar logic for rb and rrb in stack B
	if position_in_stackB < stackB.size / 2:
		rb_moves = position_in_stackB
		rrb_moves = stackB.size - position_in_stackB
	else:
		rb_moves = stackB.size - position_in_stackB
		rrb_moves = position_in_stackB

	total_moves = min(ra_moves + rb_moves, rra_moves + rrb_moves)
	-Store total_moves along with the move type decisions for this element

*/

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	calculate_moves(t_stack **stack_b, int stackA_size, int stackB_size)
{
	t_stack	*temp;
	int		index;
	int		total_moves;
	int		move_1;
	int		move_2;

	temp = *stack_b;
	total_moves = 0;
	while (temp)
	{
		index = temp->final_idx;
		ft_printf("index: %d\n", index);
		if (index < stackA_size / 2)
		{
			temp->ra = index;
			temp->rra = stackA_size - index;
		}
		else
		{
			temp->ra = stackA_size - index;
			temp->rra = index;
		}
		ft_printf("curr_pos: %d\n", temp->value);
		if (temp->value < stackB_size / 2)
		{
			temp->rb = temp->value;
			temp->rrb = stackB_size - temp->value;
		}
		else
		{
			temp->rb = stackB_size - temp->value;
			temp->rrb = temp->value;
		}
		// ft_printf("next value: %d\n", temp->next->value);
		move_1 = temp->ra + temp->rb;
		move_2 = temp->rra + temp->rrb;
		total_moves += min(move_1, move_2);
		temp = temp->next;
	}
	return (total_moves);
}

void	my_algo_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stackb_size;
	int	total_moves;

	// t_stack	*best_node;
	// int		index;
	map_values(stack_a);
	while (*stack_a != NULL)
	{
		node_push(stack_a, stack_b, "pb");
	}
	stackb_size = ft_stack_size(*stack_b);
	ft_printf("stackb_size: %d\n", stackb_size);
	// map_values(stack_b);
	// ft_printf("Best node: %d\n", best_node->value);
	while (*stack_b != NULL)
	{
		total_moves = calculate_moves(stack_b, ft_stack_size(*stack_a),
				stackb_size);
		ft_printf("total moves: %d\n", total_moves);
		node_push(stack_b, stack_a, "pa");
		// best_node = find_best_node(stack_b, stackb_size);
		// ft_printf("Best node: %d\n", best_node->value);
		// moves_best_node(stack_a, stack_b, best_node);
	}
}
