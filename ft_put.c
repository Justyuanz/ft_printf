/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:59 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/19 22:55:32 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long p)
{
	int		i;
	int		tmp;
	char	result;

	i = 0;
	if (p < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		i++;
		p = -p;
	}
	if (p > 9)
	{
		tmp = ft_putnbr(p / 10);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	result = p % 10 + '0';
	if (write(1, &result, 1) == -1)
		return (-1);
	i++;
	return (i);
}
