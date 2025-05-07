/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:09 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/07 14:08:46 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

int	isset(char c)
{
	return(c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}
int	find_specs(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));//!!in variadic function, some types are automatically converted to larger types. char -> int, give id char might crash or get garbage value bcs it was stored in 4 bytes in memory as int, not 1 byte
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'u')
		return (ft_putuint(va_arg(*ap, unsigned int)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (c == 'x') // x or X prints and integer in Hex, It treats the number as unsigned
		return (ft_puthex(va_arg(*ap, unsigned int))); //??what type -> unsigned int
	if (c == 'X') // x or X prints and integer in Hex, It treats the number as unsigned
		return (ft_puthexup(va_arg(*ap, unsigned int))); //??what type -> unsigned int
	if (c == 'p')
		return (ft_putaddress(va_arg(*ap, void *))); //who are you, pointer?
	if (c == '%')
		return (write (1, "%", 1));
	return (0);
}

int	loop_str(const char *s, va_list *ap)
{
	int	i;
	int	count;
	int	res;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			count++;
		}
		else
		{
			i++;
			if(s[i] == '\0')
				break;
			count += find_specs(s[i], ap);//call a function to deal with spec
		}
		i++;
	}
	return (count);
}
int	ft_printf(const char *format, ...)
{
	int	i;
	int count;
	
	i = 0;
	count = 0;
	if (!format || !format[0])//if(format) input validation
		return (-1);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
		}
		else if (format[i] == '%' && (!isset(format[i + 1]) || format[i + 1] == '\0'))
			return (-1);
		i++;
	}
	va_list ap;
	va_start(ap, format);
	count = loop_str(format, &ap);//call a function to loop through the string
	va_end(ap);
	return (count);
}
