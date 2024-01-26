/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:12:16 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 21:12:43 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// static void	processChar(unsigned int index, char *c)
// {
// 	printf("Character at index %u: %c\n", index, *c);
// }

// int	main(void)
// {
// 	char	str[] = "I am Spiderman";

// 	ft_striteri(str, processChar);
// 	return (0);
// }
