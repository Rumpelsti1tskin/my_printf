/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:31:29 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/06 20:31:31 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_printu(unsigned int n)
{
	char	num;
	int		count;

	num = 0;
	count = ft_count(n);
	if (n / 10 != 0)
		ft_printint(n / 10);
	num = n % 10 + '0';
	write(1, &num, 1);
	return (count);
}
