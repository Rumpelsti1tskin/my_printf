/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:42:57 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/15 17:12:47 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 16 != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ft_printlh(unsigned int n)
{
	char	*s;
	int		i;
	int		count;

	s = "0123456789abcdef";
	count = ft_count(n);
	if (n / 16 != 0)
		ft_printlh(n / 16);
	i = n % 16;
	write (1, &s[i], 1);
	return (count);
}

int	ft_printlu(unsigned int n)
{
	char	*s;
	int		i;
	int		count;

	count = ft_count(n);
	s = "0123456789ABCDEF";
	if (n / 16 != 0)
		ft_printlu(n / 16);
	i = n % 16;
	write (1, &s[i], 1);
	return (count);
}
