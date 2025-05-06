/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/06 23:38:57 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthex(unsigned long hex)
{
	int	index;
	int	i;
	const char *str;

	i = 0;
	str = "0123456789abcdef";
	if (hex > 15)
		i += ft_puthex(hex / 16);
	index = hex % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}

int	ft_puthexup(unsigned long hex)
{
	int	index;
	int	i;
	const char *str;

	i = 0;
	str = "0123456789ABCDEF";
	if (hex > 15)
		i += ft_puthexup(hex / 16);
	index = hex % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}
int	ft_putaddress(void *ptr)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	i = ft_puthex((unsigned long)ptr) + 2;
	return (i);
}
