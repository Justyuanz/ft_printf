/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:24 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/05 19:54:33 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_counthex(unsigned int hex, char c)
{
	int	index;
	int	i;
	unsigned long p;
	const char *str;
	const char *str1;

	p = (long)hex;
	i = 0;
	str = "0123456789abcdef";
	str1 = "0123456789ABCCDEF";
	if (c == 'x')
	{
		if (p > 15)
		{
			i += ft_counthex(p / 16, c); //calling ft_countnbr(p / 10); recursively — butnot using its return value, which means you're not counting the characters printed in the recursive calls.
		}
		index = p % 16 + '0';
		write(1, &str[index], 1);
		i++;
	}
	return (i);
}
