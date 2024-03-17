/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/17 00:32:06 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	print_stack(t_stack *stack, char *str)
{
	if (str)
		ft_printf("%s:\n", str);
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_find_min_node(t_stack **head)
{
	t_stack	*min;
	t_stack	*current;

	min = *head;
	current = *head;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}
int	stack_max_value(t_stack *stack)
{
	int	max;

	if (!stack)
		return (1);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

// find min value in stack
int	stack_min_value(t_stack *stack)
{
	int	min;

	if (!stack)
		return (1);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	check_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->value != value)
	{
		index++;
		stack = stack->next;
	}
	stack->final_idx = 0;
	return (index);
}

int	is_closer_to_top(t_stack *stack, int x, int len)
{
	int	distance;

	distance = 0;
	while (stack != NULL)
	{
		if (stack->value == x)
			break ;
		stack = stack->next;
		distance++;
	}
	return (distance < len / 2);
}
