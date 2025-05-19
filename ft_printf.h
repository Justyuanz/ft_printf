/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/19 23:23:53 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	isset(char c);
int	loop_str(const char *s, va_list *ap);
int	find_specs(char c, va_list *ap);
int	ft_putstr(char *s);
int	ft_putnbr(long p);
int	ft_putbase(unsigned long num, unsigned long base, char *str);
int	ft_puthex(unsigned long hex);
int	ft_puthexup(unsigned long hex);
int	ft_putaddress(void *ptr);
int	ft_putuint(unsigned int n);

#endif
