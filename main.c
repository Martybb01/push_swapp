/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:12 by marboccu          #+#    #+#             */
/*   Updated: 2024/01/26 17:56:43 by marboccu         ###   ########.fr       */
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
	t_stack *temp;	
	//t_stack *stack_b;

	stack_a = checker_input(ac, av);
	temp = stack_a;
	//stack_b = NULL;
	if (stack_a == NULL || stack_a->next == NULL)
		ft_error();

	while (stack_a)
	{
		ft_printf("stack_a = %d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	if (check_if_sorted(temp) == 1)
		ft_printf("sorted\n");
	else
		ft_printf("not sorted\n");
	
	nodes_swap(temp, temp->next, "sa");

	while (temp)
	{
		ft_printf("stack_a = %d\n", temp->value);
		temp = temp->next;
	}
	

	return (0);
}
