/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:07:04 by omiroshn          #+#    #+#             */
/*   Updated: 2018/02/01 19:07:47 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	int res1;
	int res2;

	res1 = 0;
	res2 = 0;
	res1 =    printf("%s\n", "abs");
	res2 = ft_printf("%s\n", "abs");
	printf("1: %d\n", res1);
	printf("2: %d\n", res2);
}
