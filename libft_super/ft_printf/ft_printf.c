/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:27:39 by marboccu          #+#    #+#             */
/*   Updated: 2023/11/01 14:31:26 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list params, const char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print = ft_putchar(va_arg(params, int));
	else if (c == 's')
		print = ft_putstr(va_arg(params, char *));
	else if (c == 'p')
		return (ft_puthexa(va_arg(params, uintptr_t), 0));
	else if (c == 'd' || c == 'i')
		print = ft_putnbr(va_arg(params, int));
	else if (c == 'u')
		print = ft_unint_base(va_arg(params, unsigned int));
	else if (c == 'x')
		print = (ft_hexa_low(va_arg(params, unsigned int)));
	else if (c == 'X')
		print = (ft_hexa_up(va_arg(params, unsigned int)));
	if (c == '%')
		print = ft_putchar('%');
	return (print);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		print;

	va_start(params, format);
	print = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print += ft_check_type(params, *format);
		}
		else
			print += ft_putchar(*format);
		format++;
	}
	va_end(params);
	return (print);
}

// int main()
// {
//     void *ptr;

//     int x = 42;
//     ptr = &x;

//     ft_printf("Hello %p ciao\n", ptr);
//     printf("Hello %p ciao\n", ptr);
//     return (0);
// }
