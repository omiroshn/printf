/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 20:51:04 by omiroshn          #+#    #+#             */
/*   Updated: 2018/05/12 20:51:06 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_info *info, s_num n, const char *str, int i)
{
	if (info->cast == _LONG || str[i] == 'C')
		n.cwit = va_arg(info->va_list, wchar_t);
	else
		n.cwit = (unsigned char)va_arg(info->va_list, unsigned int);
	if (info->star && info->width < 0)
	{
		info->minus = 1;
		info->width = -info->width;
	}
	if (info->width > 0)
		info->width -= 1;
	if (info->width > 0)
		info->res += info->width;
	n.wid = info->width;
	if (!info->minus && !info->zero && info->width > 0)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (!info->minus && info->zero && info->precision <= 0)
		while (info->width-- > 0)
			write(1, "0", 1);
	else if (!info->minus && info->zero)
		while (info->width-- > 0)
			write(1, " ", 1);
	if (str[i] == 'C' || info->cast == _LONG)
	{
		ft_putchar(n.cwit);
		info->res += ft_ucharlen(n.cwit);
	}
	else
	{
		write(1, &n.cwit, 1);
		info->res++;
	}
	if (info->minus)
		while (n.wid-- > 0)
			write(1, " ", 1);
	return (i);
}
