/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/26 17:30:32 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack *ft_new_node(int data)
// {
// 	t_stack *node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->value = data;
// 	node->next = NULL;
// 	return (node);
// }

// t_stack *ft_new_stack(char **values)
// {
// 	t_stack *stack;
// 	t_stack *temp;
// 	int i;

// 	stack = ft_new_node(ft_atoi(*values));
// 	temp = stack;
// 	i = 1;
// 	while (values[i])
// 	{
// 		temp->next = ft_new_node(ft_atoi(values[i]));
// 		temp = temp->next;
// 		i++;
// 	}
// 	return (stack);
// }

int main(int ac, char **av)
{
	t_stack *stack_a;

	stack_a = checker_input(ac, av);

	if (stack_a == NULL || stack_a->next == NULL)
		ft_error();
	// ft_stack_init(&stack_a, av + 1);
	while (stack_a)
	{
		ft_printf("stack_a = %d\n", stack_a->value);
		if (check_if_sorted(stack_a) == 1)
			ft_printf("sorted\n");
		stack_a = stack_a->next;
	}

	// if (check_if_sorted(stack_a) == 1)
	// 	ft_printf("OK\n");
	//  check_if_sorted(stack_a);
	// ft_printf("OK\n");
	//  ft_printf("ciao\n");
	return (0);
}
