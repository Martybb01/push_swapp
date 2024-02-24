/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:36:41 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/24 17:42:39 by marboccu         ###   ########.fr       */
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

int	ft_syntax_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 45 || str[i] == 43 || (str[i] >= 48
				&& str[i] <= 57))
		{
			if (str[i + 1] == 43 || str[i + 1] == 45)
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int	ft_duplicate_error(t_stack *stack, int num)
{
	if (stack == NULL)
		return (0);
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_sign_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if ((str[i + 1] == 32 && str[i - 1] == 32) || (str[i + 1] == '\0'))
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
