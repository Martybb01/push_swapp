/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:45:33 by marboccu          #+#    #+#             */
/*   Updated: 2024/03/27 11:52:23 by marboccu         ###   ########.fr       */
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
int	ft_check_spaces(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		exit(0);
	if (str[0] == ' ' || str[len - 1] == ' ' || ft_strnstr(str, "  ", len))
		return (0);
	return (1);
}

int	ft_is_valid(int ac, char **av)
{
	while (ac > 1)
	{
		if (ft_strchr(av[ac - 1], ' '))
			return (1);
		ac--;
	}
	return (0);
}

t_stack	*parse_stack(char **tmp, int free_tmp)
{
	t_stack	*stack_a;
	char	**matrix;
	int		i;
	int		j;

	i = -1;
	stack_a = NULL;
	matrix = NULL;
	if (free_tmp)
		matrix = tmp;
	while (tmp[++i])
	{
		j = ft_atol(tmp[i]);
		if (j == 0 && (tmp[i][0] == '\0' || (tmp[i][0] != '0')))
			return (mega_free(stack_a, NULL, NULL, matrix), NULL);
		if (ft_sign_error(tmp[i]) || ft_syntax_error(tmp[i])
			|| ft_duplicate_error(stack_a, j))
			mega_free(stack_a, NULL, NULL, matrix);
		ft_add_new_node(&stack_a, j);
	}
	if (free_tmp)
		ft_free_matrix(tmp);
	return (stack_a);
}

t_stack	*checker_input(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	if (ac == 1)
		exit(0);
	if (ac == 2 && ft_strlen(av[1]) == 0)
		ft_error();
	if (ac == 2)
	{
		if (!ft_check_spaces(av[1]))
			ft_error();
		av = ft_split(av[1], 32);
		stack_a = parse_stack(av, 1);
	}
	else if (ac > 2)
	{
		if (ft_is_valid(ac, av))
			ft_error();
		stack_a = parse_stack(av + 1, 0);
	}
	return (stack_a);
}
