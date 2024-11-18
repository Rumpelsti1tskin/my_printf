/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:14:16 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/15 17:16:32 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long long n)
{
	int	count;

	count = 3;
	while (n / 16 != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static int	ft_printptr1(unsigned long long n)
{
	unsigned int		count;
	char				*s;
	unsigned long long	i;

	s = "0123456789abcdef";
	count = ft_count(n);
	if (n / 16 != 0)
		ft_printptr1(n / 16);
	i = n % 16;
	write(1, &s[i], 1);
	return (count);
}

int	ft_printptr(void *ptr)
{
	unsigned long long	n;

	n = (unsigned long long) ptr;
	write(1, "0x", 2);
	return (ft_printptr1(n));
}
