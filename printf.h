/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/06 19:05:37 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int a);
int	ft_putstr(char * s);
int	ft_putnbr(int n);
int ft_putuint(unsigned int n);
int	ft_puthex(unsigned long hex);
int	ft_puthexup(unsigned long hex);
int	ft_putaddress(void *ptr);

#endif
