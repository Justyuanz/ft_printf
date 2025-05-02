/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:08:20 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/29 13:00:06 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	node: node is a real struct in memory.
It immediately exists on the stack (local memory).
You can access it like node.content, node.next.
t_list	*node: node is a pointer.
It does not contain a struct yet.
It only contains an address.
You must use malloc() to get real memory and assign it to the pointer.
In a linked list, each node is created dynamically.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
