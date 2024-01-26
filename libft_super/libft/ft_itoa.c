/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:03:07 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/16 21:03:52 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	len;
	int	temp;

	len = 1;
	temp = n;
	while (temp > 9 || temp < -9)
	{
		temp /= 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

static void	convert_to_string(char *result, int n, int len)
{
	int	i;
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	i = len - 1;
	while (i >= 0)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (sign == -1)
		result[0] = '-';
	result[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_length(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	convert_to_string(result, n, len);
	return (result);
}

// int main(void)
// {
//     int n;
//     char *str;

//     n = (-2147483648);
//     str = ft_itoa(n);
//     printf("La stringa è: %s\n", str);
//     free(str);
//     return (0);
// }
