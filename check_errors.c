/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:31:49 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/26 18:32:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
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
