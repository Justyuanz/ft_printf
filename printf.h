/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/07 14:10:51 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	isset(char c);
int	loop_str(const char *s, va_list *ap);
int	find_specs(char c, va_list *ap);
int	ft_putchar(int a);
int	ft_putstr(char * s);
int	ft_putnbr(int n);
int	ft_putbase(unsigned long num, int base, char *str);
int	ft_puthex(unsigned long hex);
int	ft_puthexup(unsigned long hex);
int	ft_putaddress(void *ptr);
int	ft_putuint(unsigned int n);

#endif
