/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:05:13 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:05:24 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
return value of strlcpy is always the length of src,
size_t is result of sizeof operator,
sizeof counts the '\0' while strlen does not.
size_t is an unsigned type,When you subtract 1 from 0,
you wrap around to the maximum possible value of size_t
(size_t 0)-1 == 18446744073709551615
If the return value is >= dstsize, the output string has been truncated.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (s);
}
