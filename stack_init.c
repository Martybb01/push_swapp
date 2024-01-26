/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:25:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/26 17:29:33 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_sorted(t_stack *stack_a)
{
	int i;
	// t_stack *temp;

	if (!stack_a)
		return (0);
	// temp = stack_a;

	// ft_printf("%d\n", stack_a->value);
	i = stack_a->value;
	ft_printf("i = %d\n", i);

	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			ft_printf("OK\n");
			return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);

	// while (temp)
	// {
	// 	if (temp->next && temp->value > temp->next->value)
	// 	{
	// 		printf("OK\n");
	// 		return (0);
	// 	}

	// 	temp = temp->next;

	// 	// i = stack_a->value;
	// 	// stack_a = stack_a->next;
	// }
	// printf("%d\n", temp->value);
}

// void ft_stack_init(t_stack **a, char **av)
// {
// 	long num;
// 	int i;

// 	i = 0;
// 	num = 0;
// 	while (av[i])
// 	{
// 		// if (ft_syntax_error(av[i]))
// 		// 	ft_free_error(a, av);

// 		// num = ft_atol(av[i]);

// 		// if (num > INT_MAX || num < INT_MIN)
// 		// 	ft_free_error(a, av);

// 		// if (ft_duplicate_error(*a, (int)num))
// 		// 	ft_error();

// 		ft_add_new_node(a, (int)num);
// 		i++;
// 	}
// }
