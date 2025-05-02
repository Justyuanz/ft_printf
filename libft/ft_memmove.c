/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:43:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:03:12 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copying forward is usually faster on modern CPUs due to memory caching and 
how the CPU prefetches data.
it is safe when dest<=src and they still overlap
If dest is after/more(comparing the memory address) than src,
to ensure that no data loss occurs,
the copy must start from the last byte to be copied.
To find the last byte of src and dest add the number of bytes to be copied (n),
minus 1 to exclude the ‘\0' characters.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*out;
	char	*in;
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	out = (char *)dest;
	in = (char *)src;
	if (dest <= src)
	{
		while (i < n)
		{
			out[i] = in[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			out[i] = in[i];
	}
	return (dest);
}
