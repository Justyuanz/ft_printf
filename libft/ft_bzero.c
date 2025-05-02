/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:56:06 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 12:56:38 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*integer constant literal 0 == '\0'
'\0' is defined to be a null character
- that is a character with all bits set to zero.
'\0' is (like all character literals) an integer constant,
in this case with the value zero. So
'\0' is completely equivalent to an unadorned 0 integer constant
"null character (NUL)" is easiest to rule out. '\0' is a character literal.
In C, it is implemented as int, so, it's the same as 0,
NULL is not guaranteed to be 0 -- its exact value is architecture-dependent.
Most major architectures define it to (void*)0
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
