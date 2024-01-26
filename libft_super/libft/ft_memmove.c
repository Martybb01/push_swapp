/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:03:19 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 17:44:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest2[i] = src2[i];
		}
	}
	else
	{
		i = 0;
		ft_memcpy(dest2, src2, n);
	}
	return (dest);
}

// int main()
// {
//     char src[] = "Spiderman";
//     char dest[] = "boh";
//     char src2[] = "Spiderman";
//     char dest2[] = "boh";
//     size_t n = 3;

//     ft_memmove(dest, src, n);
//     memmove(dest2, src2, n);
//     printf("src after memmove: %s\n", src);
//     printf("dest after memmove: %s\n", dest);
//     printf("src after memmove: %s\n", src2);
//     printf("dest after memmove: %s\n", dest2);
//     return (0);
// }
