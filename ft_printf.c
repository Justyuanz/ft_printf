/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:09 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/06 00:37:54 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	find_specs(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_countchar(va_arg(*ap, int)));//!!in variadic function, some types are automatically converted to larger types. char -> int, give id char might crash or get garbage value bcs it was stored in 4 bytes in memory as int, not 1 byte
	if (c == 's')
		return (ft_countstr(va_arg(*ap, char *)));
	if (c == 'u')
		return (ft_countuint(va_arg(*ap, unsigned int)));
	if (c == 'i' || c == 'd')
		return (ft_countnbr(va_arg(*ap, int)));
	if (c == 'x') // x or X prints and integer in Hex, It treats the number as unsigned
		return (ft_counthex(va_arg(*ap, unsigned int))); //??what type -> unsigned int
	if (c == 'X') // x or X prints and integer in Hex, It treats the number as unsigned
		return (ft_counthexup(va_arg(*ap, unsigned int))); //??what type -> unsigned int
	if (c == 'p')
		return (ft_countaddress(va_arg(*ap, void *))); //who are you, pointer? ->ok you are also unsigned int
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	loop_str(const char *s, va_list ap)
{
	int	i;
	int	count;

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
			count = find_specs(s[i], &ap) + count;//call a function to deal with specs
		}
		i++;
	}
	return (count);
}
int	ft_printf(const char *format, ...)
{
	int	count;

	//if(format) input validation
	count = 0;
	va_list ap;
	va_start(ap, format);
	count = loop_str(format, ap);//call a function to loop through the string
	va_end(ap);
	return (count);
}

int	main(void)
{
	char a = 'A';
	char *b= NULL;
	int	c = 42;
	int	d = -420;
	int count = 0;
	unsigned int e = 420;
	unsigned int f = 67544;
	unsigned int g = 67544;
	//const char *fmt = "char: %c, string:%s, pointer: %%, decimal: %d, int:%i, unsigned decimal:%u,";// hex lower:%x, hex higher:%X, percent sign:%p";
	count = ft_printf("char:%c,string:%s,decimal:%d,int:%i,unsigned:%u,hex::%x,hexup:%X,pointer:%p, %%:%%", a, b, c, d, e,f,g,&a);
	__builtin_printf("\n%i", count);
}