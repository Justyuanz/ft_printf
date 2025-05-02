/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:05:48 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:04:55 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Strlcat() tries to concatenate src to the end of dst,
but only within a total buffer of size size, including the null terminator.
The return value is not the number of characters copied,
but the total length of the string it TRIED to create.
When size == 0,you are not allowed to even look into the destination buffer.i
So when size <= dslen,
nothing can be appended after dst, it tried to create size + srclen string,
but there is no room to fit.
Truncation in strlcat() happens when not all characters from src can be appended
to dst because the total would exceed the buffer size (size).
check for trunction: size_t result = strlcat(dst, src,
size); if (result >= size)
when size > dstlen, it tries to create dstlen + srclen length's string,
it ends when size is reached and src is not '\0\(safety check);
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	if (!dst && size == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (size <= dstlen)
	{
		return (size + srclen);
	}
	else
	{
		while (i + 1 < size - dstlen && src[i] != '\0')
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = '\0';
		return (dstlen + srclen);
	}
}
