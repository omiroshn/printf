/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:51:00 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:51:00 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(t_info *info, s_num n, const char *str, int i)
{
	if (!(n.s = va_arg(info->va_list, char*)))
		n.s = "(null)";
	if (info->star && info->width < 0)
	{
		info->minus = 1;
		info->width = -info->width;
	}
	if (info->width > 0 && ft_strlen(n.s) > info->precision)
	{
		if (info->precision >= 0 && info->dot)
			info->width -= info->precision;
		else
			info->width -= ft_strlen(n.s);
	}
	if (info->precision > 0 && ft_strlen(n.s) < info->precision)
		info->width -= ft_strlen(n.s);
	if (info->width > 0)
		info->res += info->width;
	n.wid = info->width;
	if (!info->minus && !info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (info->precision >= 0 && ft_strlen(n.s) > info->precision && info->dot)
	{
		ft_putstrl(n.s, info->precision);
		info->res += info->precision;
	}
	else
	{
		ft_putstr(n.s);
		info->res += ft_strlen(n.s);
	}
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	return (i);
}
