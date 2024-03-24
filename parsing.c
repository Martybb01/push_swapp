/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:45:33 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/24 18:12:46 by marboccu         ###   ########.fr       */
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
	num *= sign;
	if (num == INT_MIN)
		return (INT_MIN);
	else if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (num);
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
	if (!tmp || tmp[0] == NULL)
		mega_free(NULL, tmp);
	while (tmp[i])
	{
		j = ft_atol(tmp[i]);
		if (j == 0 && (tmp[i][0] == '\0' || (tmp[i][0] != '0')))
			return (mega_free(stack_a, tmp), NULL);
		if (ft_sign_error(tmp[i]) || ft_syntax_error(tmp[i])
			|| ft_duplicate_error(stack_a, j))
			mega_free(stack_a, tmp);
		ft_add_new_node(&stack_a, j);
		i++;
	}
	ft_free_matrix(tmp);
	return (stack_a);
}

int	ft_is_valid(int ac, char **av)
{
	int	string_count;
	int	int_count;
	int	i;
	int	j;

	string_count = 0;
	int_count = 0;
	i = 1;
	j = 0;
	while (ac > 1)
	{
		if (ft_strchr(av[ac - 1], ' '))
			string_count++;
		else if (av[i][j] >= '0' && av[i][j] <= '9')
			int_count++;
		ac--;
	}
	if (string_count > 1)
		return (1);
	else if (string_count == 1 && int_count > 0)
		return (1);
	return (0);
}

t_stack	*checker_input(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 0;
	stack_a = NULL;
	if (ac == 1)
		ft_error();
	if (ac == 2)
		stack_a = checker_string(av);
	else if (ac > 2)
	{
		while (++i < ac)
		{
			j = ft_atol(av[i]);
			if (j == 0 && (av[i][0] == '\0' || (av[i][0] != '0')))
				return (mega_free(stack_a, NULL), NULL);
			if (ft_is_valid(ac, av) || ft_sign_error(av[i])
				|| ft_syntax_error(av[i]) || ft_duplicate_error(stack_a, j))
				mega_free(stack_a, NULL);
			ft_add_new_node(&stack_a, j);
		}
	}
	return (stack_a);
}
