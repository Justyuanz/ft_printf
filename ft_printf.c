#include "libft.h"
#include "printf.h"
#include <stdarg.h>

void	find_specs(char c, int count, va_list ap)
{
	if (c == 'c' || c =='%')
		ft_putchar(va_arg(ap, int));//!!in variadic function, some types are automatically converted to larger types. char -> int, give id char might crash or get garbage value bcs it was stored in 4 bytes in memory as int, not 1 byte
	if (c == 's')
		ft_putstr(va_arg(ap, char *));
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(ap, int));
	if (c == 'u')
		ft_unsigned_nbr(va_arg(ap, unsigned));
	if (c == 'x' || c == 'X') // x or X prints and integer in Hex, It treats the number as unsigned
		ft_hex(va_arg(ap,unsigned int)); //??what type
	if (c == 'p')
		ft_pointer(va_arg(ap, unsigned int)); //who are you, pointer?
}
static	int	loop_str(const char *s)
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
			ft_print(s[i], count, i);//call a function to deal with specs
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
	count = loop_str(format);//call a function to loop through the string
	va_end(ap);
	return (count);
}
int	main(void)
{
	"char: %c, string:%s, pointer: %p, decimal: %d "
	"int:%i, unsigned decimal:%u, hex lower:%x, hex higher:%X, percent sign:%%"
}