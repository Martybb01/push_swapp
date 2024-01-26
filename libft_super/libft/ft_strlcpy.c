/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:09:52 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:09:52 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main()
// {
// 	char src[] = "Hello, world!";
// 	char dest[10];
// 	char src2[] = "Hello, world!";
// 	char dest2[10];
// 	unsigned int len = ft_strlcpy(dest, src, 6);
// 	unsigned int len2 = strlcpy(dest2, src2, 6);

// 	printf("String dest is: %s\n", dest);  // String dest is: Hello
// 	printf("Length of src is: %d\n", len); // Length of src is: 13
// 	printf("String dest is: %s\n", dest2);
// 	printf("Length of src is: %d\n", len2);
// 	return (0);
// }
