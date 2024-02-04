/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/04 11:57:20 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *temp_a;
	t_stack *stack_b;
	t_stack *temp_b;

	stack_a = checker_input(ac, av);
	temp_a = stack_a;

	stack_b = NULL;
	ft_add_new_node(&stack_b, 3);
	ft_add_new_node(&stack_b, 2);
	temp_b = stack_b;

	print_stack(temp_b, "stack_b");

	if (check_if_sorted(temp_b) == 1)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");

	// if (stack_a == NULL)
	// 	ft_error();

	print_stack(temp_a, "stack_a");

	if (check_if_sorted(temp_a) == 1)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");

	// nodes_swap(temp_a, "sa");
	//  nodes_swap(temp_b, "sb");
	//  nodes_double_swap(temp_a, temp_b);
	//  nodes_rotate(&temp_a, "ra");
	//  nodes_rotate(&temp_b, "rb");
	// nodes_double_rotate(&temp_a, &temp_b);

	// nodes_reverse_rotate(&temp_a, "rra");
	//  nodes_reverse_rotate(&temp_b, "rrb");
	//  nodes_double_reverse_rotate(&temp_a, &temp_b);

	// node_push(&temp_a, &temp_b, "pb");

	if (check_if_sorted(temp_a))
		return (0);
	else
	{
		// sort_under_three(&temp_a, ft_stack_size(temp_a));
		// sort_under_three(&temp_b, ft_stack_size(temp_b));
		sort_five(&temp_a, &temp_b);
	}

	print_stack(temp_a, "stack_a");

	print_stack(temp_b, "stack_b");

	return (0);
}
