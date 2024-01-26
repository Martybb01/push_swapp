/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:00:37 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/18 12:22:08 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substr(const char *str, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static char	*create_substr(const char *str, int start, int end)
{
	int		i;
	char	*substr;

	i = 0;
	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str || !substr)
		return (0);
	while (start < end)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	int		trigger;
	char	**result;

	i = 0;
	j = 0;
	trigger = -1;
	result = malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && trigger < 0)
			trigger = i;
		else if ((s[i] == c || i == ft_strlen(s)) && trigger >= 0)
		{
			result[j] = create_substr(s, trigger, i);
			j++;
			trigger = -1;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}

// int main(void)
// {
// 	char **result;
// 	char *s;
// 	char c;

// 	s = "      SPlit|this|for|me||!|";
// 	c = '|';
// 	result = ft_split(s, c);
// 	while (*result)
// 	{
// 		printf("%s\n", *result);
// 		result++;
// 	}
// 	return (0);
// }
