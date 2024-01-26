/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:57:28 by marboccu          #+#    #+#             */
/*   Updated: 2023/10/30 20:53:59 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		i++;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_unint_base(unsigned int nb)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789";
	if (nb >= 10)
	{
		i += ft_unint_base(nb / 10);
		i += ft_unint_base(nb % 10);
	}
	else
	{
		i += ft_putchar(base[nb]);
	}
	return (i);
}

int	ft_puthexa(uintptr_t ptr, int num)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (!ptr && !num)
		return (ft_putstr("(nil)"));
	if (!num)
		i += ft_putstr("0x");
	if (ptr >= 16)
	{
		i += ft_puthexa(ptr / 16, 1);
		i += ft_puthexa(ptr % 16, 1);
	}
	else
		i += ft_putchar(base[ptr]);
	return (i);
}
