/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:11:52 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:04:33 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
'\0' is part of the string. Used strlen there because I wanna loop through
 * the '\0' char as well
the return type is char *, that is why it needs casting in the  return,
s+i is pointer arithmetic
The original function segfaults if *s is NULL
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = ft_strlen(s);
	while (i <= b)
	{
		if ((unsigned char)c == s[i])
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
