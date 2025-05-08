/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:59 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/08 11:53:20 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	return (write(1, &a, 1));
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
	int		i;
	long	p;
	char	result;

	p = (long)n;
	i = 0;
	result = 0;
	if (p < 0)
	{
		write(1, "-", 1);
		i++;
		p = -p;
	}
	if (p > 9)
	{
		i += ft_putnbr(p / 10);
	}
	result = p % 10 + '0';
	write(1, &result, 1);
	i++;
	return (i);
}
