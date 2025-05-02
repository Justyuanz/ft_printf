/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:40:55 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:07:05 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurrence of the null-terminated string needle in the string
haystack,
where not more than len characters are searched.

If needle is an empty string, haystack is returned;
if needle occurs nowhere in haystack, NULL is returned;
otherwise a pointer to the first character of the first occurrence of needle is
returned.

needle[i] && haystack[j + i] == needle[i] → compares each char of needle
(j + i) < len → makes sure we don’t go past the allowed buffer
needle[i] == '\0' → means we matched the whole needle
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needlelen;

	j = 0;
	needlelen = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (j < len && haystack[j] != '\0')
	{
		i = 0;
		while ((j + i) < len && needle[i] && needle[i] == haystack[j + i])
		{
			i++;
		}
		if (needle[i] == '\0')
		{
			return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
