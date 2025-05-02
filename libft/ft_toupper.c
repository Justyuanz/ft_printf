/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:25:38 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:07:22 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Toupper() expects only values between 0–255,
signed char or int might cause udefined	behaviour(that is why we need to cast
to unsigned char),
EOF is defined as -1, and undefined behaviour is okay
Int cast to unsigned char
0-0 65-65 255-255 256-0 257-1 -1-255 -23-233 -128-128 -256-0 -257-255
Only values cast from 0 to 255 remain the same as the original
*/

int	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
