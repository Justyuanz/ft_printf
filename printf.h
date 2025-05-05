/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:17:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/05 19:52:15 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_countchar(int a);
int	ft_countstr(char * s);
int	ft_countnbr(int n);
int ft_countuint(unsigned int n);
int	ft_counthex(unsigned int hex, char c);
#endif
