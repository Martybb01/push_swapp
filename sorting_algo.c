/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:24:56 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/03 22:39:53 by marboccu         ###   ########.fr       */
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

void	calculate_moves(t_stack *stack, int stacka_size, int stackb_pos,
		int stackb_size)
{
	stack->ra = 0;
	stack->rb = 0;
	stack->rra = 0;
	stack->rrb = 0;
	// Calculate moves in stack A (ra and rra)
	ft_printf("stack->final_idx: %d\n", stack->final_idx);
	if (stack->final_idx <= stacka_size / 2)
		stack->ra = stack->final_idx;
	else
		stack->rra = stacka_size - stack->final_idx;
	// Calculate moves in stack B (rb and rrb)
	if (stackb_pos <= stackb_size / 2)
		stack->rb = stackb_pos;
	else
		stack->rrb = stackb_size - stackb_pos;
	ft_printf("ra: %d, rb: %d, rra: %d, rrb: %d\n", stack->ra, stack->rb,
		stack->rra, stack->rrb);
}

t_stack	*find_best_node(t_stack **stack, int stack_size)
{
	t_stack	*current;
	int		pos;
	int		min_tot_moves;
	t_stack	*best_node;
	int		total_moves;

	if (*stack == NULL)
		return (NULL);
	current = *stack;
	ft_printf("lol\n");
	ft_printf("current: %d\n", current->value);
	min_tot_moves = INT_MAX;
	best_node = NULL;
	pos = 0;
	while (current != NULL)
	{
		ft_printf("lol\n");
		calculate_moves(current, stack_size, pos, stack_size);
		total_moves = current->ra > current->rb ? current->ra : current->rb;
		total_moves = total_moves > (current->rra > current->rrb ? current->rra : current->rrb) ? total_moves : (current->rra > current->rrb ? current->rra : current->rrb);
		if (total_moves < min_tot_moves)
		{
			min_tot_moves = total_moves;
			best_node = current;
		}
		current = current->next;
		pos++;
	}
	return (best_node);
}

void	moves_best_node(t_stack **stack_a, t_stack **stack_b,
		t_stack *best_node)
{
	while (best_node->ra > 0)
	{
		nodes_rotate(stack_a, "ra");
		best_node->ra--;
	}
	while (best_node->rb > 0)
	{
		nodes_rotate(stack_b, "rb");
		best_node->rb--;
	}
	while (best_node->rra > 0)
	{
		nodes_reverse_rotate(stack_a, "rra");
		best_node->rra--;
	}
	while (best_node->rrb > 0)
	{
		nodes_reverse_rotate(stack_b, "rrb");
		best_node->rrb--;
	}
	node_push(stack_a, stack_b, "pa");
}

void	my_algo_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		stackb_size;
	t_stack	*best_node;

	// int		stacka_size;
	// stacka_size = ft_stack_size(*stack_a);
	map_values(stack_a);
	while (*stack_a != NULL)
	{
		node_push(stack_a, stack_b, "pb");
	}
	stackb_size = ft_stack_size(*stack_b);
	// calculate_moves(*stack_b, ft_stack_size(*stack_a), 0, stackb_size);
	ft_printf("ciao\n");
	// ft_printf("Best node: %d\n", best_node->value);
	while (*stack_b != NULL)
	{
		calculate_moves(*stack_b, ft_stack_size(*stack_a), 0, stackb_size);
		best_node = find_best_node(stack_b, stackb_size);
		ft_printf("Best node: %d\n", best_node->value);
		moves_best_node(stack_a, stack_b, best_node);
	}
}
