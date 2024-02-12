/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:45:33 by marboccu          #+#    #+#             */
/*   Updated: 2024/02/12 14:31:01 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	return (num * sign);
}

t_stack	*checker_string(char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 0;
	tmp = ft_split(av[1], 32);
	while (tmp[i])
	{
		ft_syntax_error(tmp[i]);
		ft_duplicate_error(stack_a, ft_atoi(tmp[i]));
		j = ft_atol(tmp[i]);
		ft_add_new_node(&stack_a, j);
		i++;
	}
	free(tmp);
	return (stack_a);
}

/*
|| (av[1][0] == ' ' && av[1][1] == ' ')
*/

t_stack	*checker_input(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if ((ac == 2 && (!av[1][0] || !av[1][1] || (av[1][0] == ' '
					&& av[1][1] == ' '))) || ac == 1)
		ft_error();
	else if (ac == 2)
		stack_a = checker_string(av);
	else if (ac > 2)
	{
		while (i < ac)
		{
			ft_syntax_error(av[i]);
			ft_duplicate_error(stack_a, ft_atoi(av[i]));
			j = ft_atol(av[i]);
			ft_add_new_node(&stack_a, j);
			i++;
		}
	}
	return (stack_a);
}
