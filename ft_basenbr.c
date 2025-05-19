/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basenbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/19 23:20:51 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long num, unsigned long base, char *str)
{
	int	index;
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (num > (base - 1))
	{
		tmp = ft_putbase(num / base, base, str);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	index = num % base;
	if (write(1, &str[index], 1) == -1)
		return (-1);
	i++;
	return (i);
}

int	ft_puthex(unsigned long hex)
{
	return (ft_putbase(hex, 16, HEX_LOWER));
}

int	ft_puthexup(unsigned long hex)
{
	return (ft_putbase(hex, 16, HEX_UPPER));
}

int	ft_putaddress(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	i = ft_puthex((uintptr_t)ptr) + 2;
	if (i == 1)
		return (-1);
	return (i);
}

int	ft_putuint(unsigned int u)
{
	return (ft_putbase(u, 10, DECIMAL));
}
