/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:36:41 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/26 12:10:58 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	mega_free(t_stack *stack_a, t_stack *stack_b, char *str, char **matrix)
{
	ft_free_all(stack_a, stack_b, str, matrix);
	ft_error();
}

void	ft_free_all(t_stack *stack_a, t_stack *stack_b, char *str,
		char **matrix)
{
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	if (str)
		free(str);
	if (matrix)
		ft_free_matrix(matrix);
}
