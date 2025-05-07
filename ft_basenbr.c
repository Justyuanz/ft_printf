/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basenbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/07 14:06:19 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putbase(unsigned long num, int base, char *str)
{
	int	index;
	int	i;

	i = 0;
	if (num > (base - 1))
		i += ft_putbase(num / base, base, str);
	index = num % base;
	write(1, &str[index], 1);
	i++;
	return (i);
}
int	ft_puthex(unsigned long hex)
{
	return (ft_putbase(hex, 16, "0123456789abcdef" ));
}
int	ft_puthexup(unsigned long hex)
{
	return (ft_putbase(hex, 16, "0123456789ABCDEF" ));
}
int	ft_putaddress(void *ptr)
{
	write(1, "0x", 2);
	return (ft_puthex((unsigned long)ptr) + 2);
}
int ft_putuint(unsigned int u)
{
	return (ft_putbase(u, 10, "0123456789"));
}
