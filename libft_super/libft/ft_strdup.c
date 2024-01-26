/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:09:11 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:09:12 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
//     char src[] = "fjrgrbrfnowp";
//     char *dest;
//     char *dest2;

//     dest = ft_strdup(src);
//     dest2 = strdup(src);
//     printf("src: %s\n", src);
//     printf("dest: %s\n", dest);
//     printf("dest2: %s\n", dest2);
//     return (0);
// }
