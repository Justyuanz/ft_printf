/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:21:36 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 14:27:58 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
An array called the file descriptor table stores an array of such objects.
The file descriptors that applications manipulate are indexes into this table.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
