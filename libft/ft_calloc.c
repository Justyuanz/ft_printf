/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:05:02 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 12:57:52 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
overflow should be checked here!If count * size is too big,
it can overflow and wrap around to a smaller number
we cannot index into void pointer or calculate their size
allocates memory for an array of n objects of SIZE bytes and initializes
all bytes in the allocated storage to zero.
nmem * sizeof(type) just as malloc
nmem = num of blocks of memories, size is bytes in each block,
*/
void	*ft_calloc(size_t nmem, size_t size)
{
	size_t			i;
	size_t			totalbytes;
	unsigned char	*ptr;

	i = 0;
	if (nmem == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return ((void *)ptr);
	}
	if (size > SIZE_MAX / nmem)
		return (NULL);
	totalbytes = nmem * size;
	ptr = malloc(totalbytes);
	if (ptr == NULL)
		return (NULL);
	while (i < totalbytes)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
