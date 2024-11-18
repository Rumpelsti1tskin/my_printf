/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:03 by ykisibek          #+#    #+#             */
/*   Updated: 2024/03/17 19:11:42 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_check(char c, va_list args)
{
	if (c == '%')
		return (ft_printchar('%'));
	else if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printu(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printlh(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printlu(va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%')
		{
			count += ft_check(print[i + 1], args);
			i += 2;
		}
		else
		{
			count += ft_printchar(print[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
