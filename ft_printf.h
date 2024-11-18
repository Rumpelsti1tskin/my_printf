/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykisibek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:51:31 by ykisibek          #+#    #+#             */
/*   Updated: 2024/02/15 17:10:24 by ykisibek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *print, ...);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_check(char c, va_list args);
int	ft_printint(int n);
int	ft_printu(unsigned int n);
int	ft_printlh(unsigned int n);
int	ft_printlu(unsigned int n);
int	ft_printptr(void *ptr);

#endif
