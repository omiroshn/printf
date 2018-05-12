/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:51:13 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:51:13 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_info *info, s_num n, const char *str, int i)
{
	if (info->plus)
		info->width--;
	if (info->width > 0)
	{
		info->width -= 1;
		info->res += info->width;
	}
	n.wid = info->width;
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (info->plus)
	{
		write(1, "+", 1);
		info->res++;
	}
	if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	write(1, "%", 1);
	info->res += 1;
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	return (i);
}
