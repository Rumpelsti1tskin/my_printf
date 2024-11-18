/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:19:56 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/06 19:19:58 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printint(int n)
{
	char	num;
	int		count;

	num = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	count = ft_count(n);
	if (-2147483648 < n && n <= 2147483647)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n / 10 != 0)
			ft_printint(n / 10);
		num = n % 10 + '0';
		write(1, &num, 1);
	}
	return (count);
}
