/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:10:58 by jinzhang          #+#    #+#             */
/*   Updated: 2025/04/30 15:28:23 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *, ...);

#endif
