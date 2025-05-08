/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinzhang <jinzhang@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:05:45 by jinzhang          #+#    #+#             */
/*   Updated: 2025/05/08 11:42:24 by jinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int 			mine_return = 0;
	int 			std_return = 0;
	char 			a = 'A';
	char 			*b= NULL;
	int				c = 0;
	int				d = -420;
	unsigned int 	e = INT_MIN;
	unsigned int 	f = 255;
	unsigned int 	g = 27544355;

	mine_return = ft_printf("Mine: Hex: %x\n", 0);
	std_return = printf("Std : Hex: %x\n", 0);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: HEX: %X\n", 305441741); 
	std_return = printf("Std : HEX: %X\n", 305441741);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: Large hex: %x\n", UINT_MAX);
    std_return  = printf("Std : Large hex: %x\n", UINT_MAX);
    printf("Returns: mine=%d, std=%d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Unsigned int:%u\n", UINT_MAX);
	std_return = printf("Std : Unsigned int:%u\n", UINT_MAX);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Address: %p\n", &main);
	std_return = printf("Std : Address: %p\n", &main);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Zero: %u %d\n", 0u, 0);
	std_return = printf("Std : Zero: %u %d\n", 0u, 0);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Neg unsigned: %u\n", INT_MIN);
	std_return = printf("Std : Neg unsigned: %u\n", INT_MIN);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: Empty string: '%s'\n", "");
    std_return  = printf("Std : Empty string: '%s'\n", "");
    printf("Empty string returns: mine=%d, std=%d\n\n", mine_return, std_return);

	mine_return = ft_printf("[c:%c],[s:%s],[d:%d],[i:%i],[ui:%u],[hex::%x],[HEX:%X],[ptr:%p],[%%:%%],[min:%i],[max:%i]\n", a, b, c, d, e,f,g,b, INT_MIN, INT_MAX);
	std_return  = printf("[c:%c],[s:%s],[d:%d],[i:%i],[ui:%u],[hex::%x],[HEX:%X],[ptr:%p],[%%:%%],[min:%i],[max:%i]\n", a, b, c, d, e,f,g,b, INT_MIN, INT_MAX);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Pointer NULL: %p\n", NULL);
	std_return = printf("Std : Pointer NULL: %p\n", NULL);
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: NULL string: %s\n", b);
    std_return  = printf("Std : NULL string: %s\n", b);
    printf("Returns: mine=%d, std=%d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: Neg unsigned: %u\n", (unsigned int)d);
    std_return  = printf("Std : Neg unsigned: %u\n", (unsigned int)d);
    printf("Returns: mine=%d, std=%d\n\n", mine_return, std_return);

    mine_return = ft_printf("");
    std_return  = printf("");
    printf("Empty format returns: mine=%d, std=%d\n\n", mine_return, std_return);

	mine_return = ft_printf(NULL);
    //std_return  = printf(NULL);
    printf("Null format returns: mine=%d, std=%d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: %%%""%%\n");
    std_return  = printf("Std : %%%""%%\n");
    printf("Multiple percents returns: mine=%d, std=%d\n\n", mine_return, std_return);

	mine_return = ft_printf("Mine: Just percent: %%%\n");
	std_return = printf("Std : Just percent: %%%\n");
	printf("Returns: ft_printf = %d, printf = %d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: Unknown: %k\n");
    std_return  = printf("Std : Unknown: %k\n");
    printf("Returns: mine=%d, std=%d\n\n", mine_return, std_return);

    mine_return = ft_printf("Mine: Lone percent at end: %\n");
    std_return  = printf("Std : Lone percent at end: %\n");
    printf("Returns: mine=%d, std=%d\n\n", mine_return, std_return);
}