/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:09:33 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:09:34 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		src_len += size;
	else
		src_len += dest_len;
	while (src[i] != '\0' && (dest_len + 1) < size)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (src_len);
}
// int	main(void)
// {
// 	char			src[] = "Hello, world!";
// 	char			dest[10];
// 	char			src2[] = "Hello, world!";
// 	char			dest2[10];
// 	unsigned int	len;
// 	unsigned int	len2;

// 	len = ft_strlcat(dest, src, 6);
// 	len2 = strlcat(dest2, src2, 6);
// 	printf("String dest is: %s\n", dest);  // String dest is: Hello
// 	printf("Length of src is: %d\n", len); // Length of src is: 13
// 	printf("String dest is: %s\n", dest2);
// 	printf("Length of src is: %d\n", len2);
// 	return (0);
// }
