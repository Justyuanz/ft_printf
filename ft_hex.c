/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/05 22:39:43 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_counthex(unsigned int hex)
{
	int	index;
	int	i;
	unsigned long p;
	const char *str;

	p = (long)hex;
	i = 0;
	str = "0123456789abcdef";
	if (p > 15)
		i += ft_counthex(p / 16);
	index = p % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}

int	ft_counthexup(unsigned int hex)
{
	int	index;
	int	i;
	unsigned long p;
	const char *str;

	p = (long)hex;
	i = 0;
	str = "0123456789ABCDEF";
	if (p > 15)
		i += ft_counthexup(p / 16);
	index = p % 16;
	write(1, &str[index], 1);
	i++;
	return (i);
}

int	ft_countaddress(void *hex)
{
	int	index;
	int	i;
	unsigned long p;
	const char *str;

	p = (unsigned long)hex;
	str = "0123456789abcdef";
	i = 2;
	if (p > 15)
		i += ft_countaddress((void *)(p / 16));
	index = p % 16;
	write(1, "0x", 2);
	write(1, &str[index], 1);
	i++;
	return (i);
}