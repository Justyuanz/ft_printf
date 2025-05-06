/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:18:09 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/06 21:51:49 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>
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
	return (-1);
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
			if(s[i] != '\0')
				res = find_specs(s[i], ap);//call a function to deal with spec
				if(res == -1)
				{
					write(1, "%" ,1);
					count = count + 2;
				}
			count += res;
		}
		i++;
	}
	return (count);
}
int	ft_printf(const char *format, ...)
{
	int	count;

	if (!format)//if(format) input validation
		return (-1);
	count = 0;
	va_list ap;
	va_start(ap, format);
	count = loop_str(format, &ap);//call a function to loop through the string
	va_end(ap);
	return (count);
}
#include <stdio.h>
int	main(void)
{
	char a = 'A';
	char *b= NULL;
	int	c = 0;
	int	d = -420;
	unsigned int e = INT_MIN;
	unsigned int f = 255;
	unsigned int g = 27544355;

	int count = ft_printf("[char:%c],[string:%s],[decimal:%d],[int:%i],[unsigned int:%u],[hex::%x],[hexup:%X],[pointer:%p],[%%:%%],[int_min:%i],[int_max:%i],[%%%z%%]\n", a, b, c, d, e,f,g,&g, INT_MIN, INT_MAX);
	int count1 = printf("[char:%c],[string:%s],[decimal:%d],[int:%i],[unsigned int:%u],[hex::%x],[hexup:%X],[pointer:%p],[%%:%%],[int_min:%i],[int_max:%i],[%%%z%%]\n", a, b, c, d, e,f,g,&g, INT_MIN, INT_MAX);
	//ft_printf("Null str: %s | Invalid spec: %z | Percent: %% | Lone percent: %\n", NULL);
	int null = printf("printf Null str: %s\n", NULL);
	int null1 = ft_printf("printf Null str: %s\n", NULL);
	int z = printf("Invalid spec: %z\n");
	int z1 = ft_printf("Invalid spec: %z\n");
	int per = printf("Percent: %%\n");
	int per1 = ft_printf("Percent: %%\n");
	int lone = printf("Lone percent: %\n");
	int lone1 = ft_printf("Lone percent: %\n");
	int zero = ft_printf(NULL);
	int zero1 = ft_printf(NULL);

	printf("\n");
	printf("ft_printf:%d\n", count);
	printf("printf:   %d\n", count1);
	printf("[count:%d],[null:%d],[invalid:%d],[percent:%d],[lone:%d],[zero:%d]\n", count, null, z, per, lone, zero);
	printf("[count:%d],[null:%d],[invalid:%d],[percent:%d],[lone:%d],[zero1:%d]\n", count1, null1, z1, per1, lone1, zero1);


}