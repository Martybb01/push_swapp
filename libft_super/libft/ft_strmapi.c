/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:17:15 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 18:17:19 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s || !f || !str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char my_toupper(unsigned int i, char c)
// {
//     return (ft_toupper(c));
// }

// int main()
// {
//     char const *s = "Hello, world!";

//     char *str = ft_strmapi(s, my_toupper);

//     printf("%s\n", str);
//     free(str);
//     return (0);
// }
