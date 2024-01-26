/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:02:40 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:02:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str1[] = "ABCDEFG";
// 	char str2[] = "ABCDXYZ";
// 	char str3[] = "ABCDEFG";
// 	char str4[] = "ABCDXYZ";

// 	printf("%d\n", ft_memcmp(str1, str2, 4));
// 	printf("%d\n", ft_memcmp(str1, str2, 7));
// 	printf("%d\n", ft_memcmp(str2, str1, 7));
// 	printf("%d\n", ft_memcmp(str3, str4, 4));
// 	printf("%d\n", ft_memcmp(str3, str4, 7));
// 	printf("%d\n", ft_memcmp(str4, str3, 7));
// 	return (0);
// }
