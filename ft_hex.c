/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/06 00:43:30 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_counthex(unsigned int hex)
{
	int	index;
	int	i;
	const char *str;
	
	i = 0;
	str = "0123456789abcdef";
	if (hex > 15)
		i += ft_counthex(hex / 16);
	index = hex % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}

int	ft_counthexup(unsigned int hex)
{
	int	index;
	int	i;
	const char *str;

	i = 0;
	str = "0123456789ABCDEF";
	if (hex > 15)
		i += ft_counthexup(hex / 16);
	index = hex % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}
int	ft_countaddress(void *ptr)
{
	int	i;
	int index;
	unsigned long hex;
	const char *str;
	
	i = 0;
	index = 0;
	hex = (unsigned long)ptr;
	write(1, "0x", 2);
	str = "0123456789abcdef";
	while (hex > 0)
	{
		hex /= 16;
		hex %= 16;
		write(1, &str[index], 1);
		index++;
		i++;
	}
	return (i);
}
