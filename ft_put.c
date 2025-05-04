/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:59 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/04 15:04:11 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
int	ft_putnbr(int n)
{
	int	i;
	long	p;
	char result;

	p = (long)n;
	i = 0;
	result = 0;
	if (p < 0)
	{
		write (1, "-", 1);
		i++;
		p = -p;
	}
	if (p > 9)
	{
		ft_putnbr(p / 10);
		i++;
	}
	result = p % 10 + '0';
	write(1, &result, 1);
	__builtin_printf("    i is this: %i\n", i);
	return (i);
}
//ft_hex(va_arg(ap,unsigned int));
//ft_pointer(va_arg(ap, unsigned int));