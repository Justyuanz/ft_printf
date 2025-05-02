/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:47:44 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:16 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	memchr(void)  and memrchr() functions return a pointer to the matching byte
or NULL if the character does not occur in the given memory area.
the difference between unsigned char pointer and char pointer
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
		{
			return ((void *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
