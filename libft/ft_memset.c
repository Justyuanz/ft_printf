/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:18:46 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:03:59 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
%p to print void pointer
%c is a print a character%.3s to print a specific amount of characters in string
printf expects the string to be null terminated,
so need to add  the \0 at the end of  the string
Type void is not assignable
void pointers can store memory addresses of any type of data values,
like malloc returns a void pointer
void *malloc(size_t size)  we cannot dereference void pointers and pointer
arithmetic does not always work with void pointer
*((char*)s) is  typecasting void pointer s to char pointer and then dereference
it to get value
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	j;
	unsigned char	*str;

	j = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = j;
		i++;
	}
	return (s);
}
