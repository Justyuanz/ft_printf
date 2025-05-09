/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:09 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/09 14:37:11 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isset(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X');
}

int	find_specs(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (c == 'u')
		return (ft_putuint(va_arg(*ap, unsigned int)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (c == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int)));
	if (c == 'X')
		return (ft_puthexup(va_arg(*ap, unsigned int)));
	if (c == 'p')
		return (ft_putaddress(va_arg(*ap, void *)));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	loop_str(const char *s, va_list *ap)
{
	int	i;
	int	count;
	int res;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			count++;
		}
		else
		{
			i++;
			if (s[i] == '\0')
				break ;
			res = find_specs(s[i], ap);
			if(res == -1)
				return (-1);
			count += res;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && (!isset(format[i + 1])
				|| format[i + 1] == '\0'))
			return (-1);
		i++;
	}
	count = loop_str(format, &ap);
	va_end(ap);
	if (count == -1)
		return (-1);
	return (count);
}
