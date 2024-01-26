/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:17:41 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:02 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	i;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end >= start && ft_strchr(set, s1[end - 1]))
		end--;
	size = end - start + 1;
	str = (char *)malloc(sizeof(*str) * size);
	if (!str)
		return (NULL);
	i = 0;
	while (end > start)
	{
		str[i++] = s1[start++];
	}
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	char str[] = "Hello World ciao!";
// 	char set[] = "Helao!";
// 	char *p;

// 	p = ft_strtrim(str, set);
// 	printf("%s", p);
// 	return (0);
// }
