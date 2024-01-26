/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:10:42 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:10:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

char	*ft_strnstr(const char *bigstr, const char *smallstr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (smallstr[i] == '\0')
		return ((char *)bigstr);
	while (bigstr[i] != '\0' && i < len)
	{
		j = 0;
		while (bigstr[i + j] == smallstr[j] && (i + j) < len)
		{
			if (smallstr[j + 1] == '\0')
				return ((char *)bigstr + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char bigstr[] = "ciao Hello mondo";
//     char smallstr[] = "Hello";

//     printf("%s\n", ft_strnstr(bigstr, smallstr, 10));
//     printf("%s", strnstr(bigstr, smallstr, 10));
//     return (0);
// }
