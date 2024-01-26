/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:52:41 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/30 20:53:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_low(unsigned int nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		i += ft_hexa_low(nb / 16);
		i += ft_hexa_low(nb % 16);
	}
	else
		i += ft_putchar(base[nb]);
	return (i);
}

int	ft_hexa_up(unsigned int nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		i += ft_hexa_up(nb / 16);
		i += ft_hexa_up(nb % 16);
	}
	else
		i += ft_putchar(base[nb]);
	return (i);
}
