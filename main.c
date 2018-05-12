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
	setlocale(P_ALL, "");

	printf("OR res: %d\n",   printf("OR: %ld\n", 11111111111));
	printf("OR res: %d\n",ft_printf("MY: %ld\n", 11111111111));

	return (0);
}
