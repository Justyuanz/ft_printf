/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:59 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/05 22:29:43 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_countchar(int a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_countstr(char *s)
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
int	ft_countnbr(int n)
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
		i += ft_countnbr(p / 10); //calling ft_countnbr(p / 10); recursively — butnot using its return value, which means you're not counting the characters printed in the recursive calls.
	}
	result = p % 10 + '0';
	write(1, &result, 1);
	i++;
	return (i);
}
int ft_countuint(unsigned int u)
{
	unsigned int	i;
	unsigned long	p;
	char result;

	p = (unsigned long)u;
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
		i += ft_countuint(p / 10);
	}
	result = p % 10 + '0';
	write(1, &result, 1);
	i++;
	return (i);
}
