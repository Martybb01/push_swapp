/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:10:24 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/17 17:45:59 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <string.h>

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

// int main()
// {
//     char *s1 = "This is a test string.";
//     char *s2 = "This is a different test string.";
//     size_t n = 10;

//     int result = ft_strncmp(s1, s2, n);
//     int result2 = strncmp(s1, s2, n);

//     if (result == 0 && result2 == 0)
//     {
//         printf("The strings are equal %zu\n", n);
//     }
//     else if (result < 0 && result2 < 0)
//     {
//         printf("first string is less than second for %zu\n", n);
//     else if (result > 0 && result2 > 0)
//     {
//         printf("first string is more than second for %zu\n", n);
//     else
//     {
//         printf("strings are not equal for %zu.\n", n);
//     }
//     return (0);
// }
