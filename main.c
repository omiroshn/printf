/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:09:16 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/06 14:10:00 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main()
{
	// setlocale(P_ALL, "");


	// assert_printf("{%05.c}", 0);

	// assert_printf("{%05.s}", 0);

	// assert_printf("{%05.%}", 0);

	// assert_printf("{%05.Z}", 0);

	// assert_printf("{%#.5x}", 1);

	// assert_printf("%#.3o", 1);

	// printf("OR res: %d\n",   printf("OR:%05.c\n", 0));
	// printf("MY res: %d\n",ft_printf("MY:%05.c\n", 0));
	// printf("OR res: %d\n",   printf("OR: |%05.s\n", 0));
	// printf("MY res: %d\n",ft_printf("MY: |%05.s\n", 0));
	// printf("OR res: %d\n",   printf("%05.%\n", 0));
	// printf("MY res: %d\n",ft_printf("%05.%\n", 0));
	// printf("OR res: %d\n",   printf("%05.Z\n", 0));
	// printf("MY res: %d\n",ft_printf("%05.Z\n", 0));
	printf("OR res: %d\n",   printf("OR: |%10.s\n", 0));
	printf("MY res: %d\n",ft_printf("MY: |%10.s\n", 0));
	// printf("OR res: %d\n",   printf("OR: |%#.3o\n", 1));
	// printf("MY res: %d\n",ft_printf("MY: |%#.3o\n", 1));
	// printf("OR res: %d\n",   printf("%4.s\n", "42"));
	// printf("MY res: %d\n",ft_printf("%4.s\n", "42"));
	// printf("OR res: %d\n",   printf("%.2s is a string\n", "this"));
	// printf("MY res: %d\n",ft_printf("%.2s is a string\n", "this"));
	// printf("OR res: %d\n",   printf("OR: %5.2s is a string\n", "this"));
	// printf("MY res: %d\n",ft_printf("MY: %5.2s is a string\n", "this"));
	// printf("OR res: %d\n",   printf("OR: %.2s is a string\n", ""));
	// printf("MY res: %d\n",ft_printf("MY: %.2s is a string\n", ""));
	// printf("OR res: %d\n",   printf("OR: %5.2s is a string\n", ""));
	// printf("MY res: %d\n",ft_printf("MY: %5.2s is a string\n", ""));
	// printf("OR res: %d\n",   printf("%-10s is a string\n", "this"));
	// printf("MY res: %d\n",ft_printf("%-10s is a string\n", "this"));
	// printf("OR res: %d\n",   printf("%-.2s is a string\n", "this"));
	// printf("MY res: %d\n",ft_printf("%-.2s is a string\n", "this"));
	// printf("OR res: %d\n",   printf("%-5.2s is a string\n", "this"));
	// printf("MY res: %d\n",ft_printf("%-5.2s is a string\n", "this"));
	// printf("OR res: %d\n",   printf("%-.2s is a string\n", ""));
	// printf("MY res: %d\n",ft_printf("%-.2s is a string\n", ""));
	// printf("OR res: %d\n",   printf("%-5.2s is a string\n", ""));
	// printf("MY res: %d\n",ft_printf("%-5.2s is a string\n", ""));
	// printf("OR res: %d\n",   printf("%s %s\n", "this", "is"));
	// printf("MY res: %d\n",ft_printf("%s %s\n", "this", "is"));
	// printf("OR res: %d\n",   printf("%s %s %s\n", "this", "is", "a"));
	// printf("MY res: %d\n",ft_printf("%s %s %s\n", "this", "is", "a"));
	// printf("OR res: %d\n",   printf("%s %s %s %s\n", "this", "is", "a", "multi"));
	// printf("MY res: %d\n",ft_printf("%s %s %s %s\n", "this", "is", "a", "multi"));
	// printf("OR res: %d\n",   printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string"));
	// printf("MY res: %d\n",ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string"));
	// printf("OR res: %d\n",   printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string"));
	// printf("MY res: %d\n",ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string"));
	// printf("OR res: %d\n",   printf("@moulitest: %s\n", NULL));
	// printf("MY res: %d\n",ft_printf("@moulitest: %s\n", NULL));
	// printf("OR res: %d\n",   printf("%s %s\n", NULL, "string"));
	// printf("MY res: %d\n",ft_printf("%s %s\n", NULL, "string"));

	return (0);
}
