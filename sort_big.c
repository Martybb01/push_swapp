/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:03:18 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/15 18:44:06 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.
// int	rotate_type_ab(t_stack **stack_a, t_stack **stack_b)
// {
// }

// void	sort_stack_until_three(t_stack **stack_a, t_stack **stack_b)
// {
// 	// t_stack	*temp;
// 	(void)stack_b;
// 	// int		i;
// 	while (ft_stack_size(*stack_a) > 3)
// 	{
// 		// temp = *stack_a;
// 		// i = rotate_type_ab(stack_a, stack_b);
// 		ft_printf("daje\n");
// 		// while (temp)
// 		// {
// 		// 	ft_printf("stack a: %d\n", temp->value);
// 		// 	// ft_printf("index: %d\n", i);
// 		// 	temp = temp->next;
// 		// }
// 	}
// }

int	get_nth_value(t_stack *stack, int n)
{
	int		idx;
	t_stack	*current;

	idx = 0;
	current = stack;
	while (current != NULL && idx < n)
	{
		current = current->next;
		idx++;
	}
	if (current != NULL)
		return (current->value);
	else
		ft_error();
	return (0);
}

int	moves_calculation(int idx_a, int idx_b, int stack_a_size, int stack_b_size)
{
	int	ra_moves;
	int	rra_moves;
	int	rb_moves;
	int	rrb_moves;
	int	ra_rb_moves;
	int	rra_rrb_moves;
	int	min_moves;

	ra_moves = idx_a;
	rra_moves = stack_a_size - idx_a;
	rb_moves = idx_b;
	rrb_moves = stack_b_size - idx_b;
	ra_rb_moves = ft_max(ra_moves, rb_moves);
	rra_rrb_moves = ft_max(rra_moves, rrb_moves);
	min_moves = ft_min(ra_moves + rb_moves, rra_moves + rrb_moves);
	min_moves = ft_min(min_moves, ra_rb_moves);
	min_moves = ft_min(min_moves, rra_rrb_moves);
	return (min_moves);
}

int	find_index_place(t_stack *stack, int num, char c)
{
	int		index;
	t_stack	*temp;
	t_stack	*last_node;

	index = 0;
	last_node = ft_find_last_node(stack);
	ft_printf("pippo\n");
	// ft_printf("last node: %d\n", last_node->value);
	if (c == 'a')
	{
		ft_printf("num: %d\n", num);
		// ft_printf("stack value: %d\n", stack->value);
		if (num < stack->value && num > last_node->value)
		{
			ft_printf("Lol\n");
			index = 0;
		}
		else if (num < stack_min_value(stack) || num > stack_max_value(stack))
		{
			ft_printf("Loool\n");
			index = check_index(stack, stack_min_value(stack));
		}
		else
		{
			temp = stack->next;
			while (stack->value > num || num > temp->value)
			{
				ft_printf("super\n");
				stack = stack->next;
				temp = stack->next;
				index++;
			}
		}
	}
	else if (c == 'b')
	{
		ft_printf("num: %d\n", num);
		// ft_printf("stack value: %d\n", stack->value);
		// ft_printf("last node: %d\n", last_node->value);
		if (num > stack->value && num < ft_find_last_node(stack)->value)
		{
			ft_printf("Lol\n");
			index = 0;
		}
		else if (num > stack_max_value(stack) || num < stack_min_value(stack))
		{
			ft_printf("Loool\n");
			index = check_index(stack, stack_max_value(stack));
		}
		else
		{
			temp = stack->next;
			ft_printf("num: %d\n", num);
			ft_printf("stack value: %d\n", stack->value);
			ft_printf("temp value: %d\n", temp->value);
			while (num > stack->value || num < temp->value)
			{
				ft_printf("Looooool\n");
				stack = stack->next;
				temp = stack->next;
				index++;
			}
		}
	}
	return (index);
}

t_move	best_node_to_push(t_stack *stack_a, t_stack *stack_b)
{
	t_move	best_move;
	int		stack_a_size;
	int		stack_b_size;
	int		i;
	int		num;
	int		idx_b;
	int		tot_moves;

	best_move.tot_moves = INT_MAX;
	stack_a_size = ft_stack_size(stack_a);
	stack_b_size = ft_stack_size(stack_b);
	i = 0;
	while (i < stack_a_size)
	{
		num = get_nth_value(stack_a, i);
		idx_b = find_index_place(stack_b, num, 'b');
		tot_moves = moves_calculation(i, idx_b, stack_a_size, stack_b_size);
		ft_printf("boh\n");
		if (tot_moves < best_move.tot_moves)
		{
			best_move.idx_a = i;
			best_move.idx_b = idx_b;
			best_move.tot_moves = tot_moves;
		}
	}
	return (best_move);
}

void	sort_stack_b_from_a(t_stack **stack_a, t_stack **stack_b)
{
	t_move	best_move;

	node_push(stack_a, stack_b, "pb");
	node_push(stack_a, stack_b, "pb");
	if (ft_stack_size(*stack_a) > 3)
	{
		ft_printf("pushing to b\n");
		best_move = best_node_to_push(*stack_a, *stack_b);
		ft_printf("best move: %d\n", best_move.tot_moves);
	}
	if (ft_stack_size(*stack_a) == 3)
	{
		sort_three(stack_a);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	place_in_b;

	map_values(stack_a);
	// sort_stack_b_from_a(stack_a, stack_b);
	// ft_printf("stackk value: %d\n", (*stack_a)->value);
	index = check_index(*stack_a, stack_min_value(*stack_a));
	ft_printf("min value: %d\n", stack_min_value(*stack_a));
	ft_printf("index: %d\n", index);
	node_push(stack_a, stack_b, "pb");
	node_push(stack_a, stack_b, "pb");
	place_in_b = find_index_place(*stack_b, (*stack_a)->value, 'b');
	ft_printf("place: %d\n", place_in_b);
	// sort_stack_b_from_a(stack_a, stack_b);
	if (index < ft_stack_size(*stack_a) - index)
	{
		while (index > 0)
		{
			nodes_rotate(stack_a, "ra");
			index--;
		}
	}
	else
	{
		while (index < ft_stack_size(*stack_a))
		{
			nodes_reverse_rotate(stack_a, "rra");
			index++;
		}
	}
}
