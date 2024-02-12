/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/11 19:19:47 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	ft_add_new_node(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = num;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = ft_find_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
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

// Return a pointer to a node in a linked list with the max value on it and its index
t_stack	*stack_max_value(t_stack *stack)
{
	t_stack	*max;
	int		i;

	i = 0;
	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
		{
			max = stack;
			max->final_idx = i;
		}
		stack = stack->next;
		i++;
	}
	ft_printf("l'indice del valore massimo è %d\n", max->final_idx);
	return (max);
}

// find min value in stack
t_stack	*stack_min_value(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*stack_top_value(t_stack *stack)
{
	t_stack	*top;

	top = stack;
	while (stack)
	{
		if (stack->final_idx == 0)
		{
			top = stack;
			break ;
		}
		stack = stack->next;
	}
	return (top);
}

// calculate distance of every number from top position in stack b
void	calculate_distance(t_stack **stack_b, int len)
{
	t_stack	*temp;
	int		i;
	int		value;

	i = 0;
	temp = *stack_b;
	while (i < len)
	{
		temp->curr_pos = i;
		value = temp->value;
		if (temp->curr_pos <= len / 2)
			value = temp->curr_pos;
		else
			value = temp->curr_pos - len;
		ft_printf("L'elemento %d ha valore %d e distanza %d\n", i + 1,
			temp->value, value);
		temp = temp->next;
		i++;
	}
}

int	is_closer_to_top(t_stack *stack, int x, int len)
{
	int distance;

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
