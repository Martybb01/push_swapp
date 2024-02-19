/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/19 20:32:10 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	routing(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_size(*stack_a);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			nodes_swap(*stack_a, "sa");
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len > 3 && len <= 5)
		sort_small(stack_a, stack_b, len);
	else
		// 	sort_big(stack_a, stack_b, len);
		// quicksort_stack(stack_a, 0, len - 1);
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp_a;
	t_stack	*stack_b;
	t_stack	*temp_b;

	stack_a = checker_input(ac, av);
	temp_a = stack_a;
	stack_b = NULL;
	temp_b = stack_b;
	// if (stack_a == NULL)
	// 	ft_error();
	// print_stack(temp_a, "stack_a");
	if (check_if_sorted(temp_a))
	{
		return (0);
	}
	else
		routing(&temp_a, &temp_b);
	// print_stack(temp_a, "stack_a");
	// print_stack(temp_b, "stack_b");
	ft_free_stack(temp_a);
	return (0);
}
