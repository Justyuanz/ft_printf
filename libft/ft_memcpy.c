/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:55:44 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:49 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
We do not need to handle the case when the behaviour is said to be undefined
because it affects running time
Memcpy is copying memory byte by byte
if  we try to write past the allocated memory of dst,
there might be weird garbage output or segfault
If copying strings or part of a string using memcpy,
always null-terminate manually if you're going to treat it as a C string
e.g. printf("%s")
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	i = 0;
	if (!dest && !src)
		return (NULL);
	to = (char *)dest;
	from = (const char *)src;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}
