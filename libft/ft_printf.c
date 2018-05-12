/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:39:22 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/30 18:23:40 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(uintmax_t n)
{
	char		*str;
	uintmax_t	temp;
	uintmax_t	len;
	uintmax_t	minus;

	len = ((n <= 0) ? 1 : 0);
	temp = n;
	while (++len && temp)
		temp /= 10;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	*str = '0';
	temp = n;
	while (temp)
	{
		str[--len] = '0' + 1 * (temp % 10);
		temp /= 10;
	}
	return (str);
}

int		ft_intlen_u(uintmax_t num)
{
	int count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int		ft_intlen(intmax_t num)
{
	int count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

void	init_flags(t_info *info)
{
	info->hash = 0;
	info->minus = 0;
	info->plus = 0;
	info->zero = 0;
	info->space = 0;
	info->star = 0;
	info->width = 0;
	info->precision = 0;
	info->dot = 0;
	info->cast = 0;
	info->smt = 0;
	info->changed = 0;
}

int		ft_ucharlen(int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

int		ft_ustrlen(wchar_t *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while(str[i])
		len += ft_ucharlen(str[i++]);
	return (len);
}

int		ft_putustrl(wint_t *s, int len)
{
	int i;
	int count;
	int ret;

	i = -1;
	count = 0;
	ret = 0;
	if (ft_ustrlen(s) < len)
	{
		while (*s)
			ft_putchar(*s++);
		return (len);
	}
	else
		while (++i < len)
		{
			count += ft_ucharlen(s[i]);
			if (count <= len)
			{
				ret += ft_ucharlen(s[i]);
				ft_putchar(s[i]);
			}
		}
	return (ret);
}

int		ft_spreclen(wint_t *s, int len)
{
	int i;
	int count;
	int ret;

	count = 0;
	ret = 0;
	i = -1;
	while (++i < len)
	{
		count += ft_ucharlen(s[i]);
		if (count <= len)
			ret += ft_ucharlen(s[i]);
	}
	return (ret);
}

void	ft_putustr(wint_t *s)
{
	while (*s)
		ft_putchar(*s++);
}

void	ft_putstrl(char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		write(1, &str[i], 1);
}

int		count_width(const char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		count_stoi(const char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

int		someth_else(char c)
{
	if (c != '-' || c != '+' || c != ' ' || c != '#' || c != '0'
		|| c != '*' || c != '.' || !(c > '0' && c <= '9'))
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
		|| c == 'D' || c == 'i' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		parse_flags(t_info *info, const char *str, int i)
{
	if (str[i] == '-' && i++ && (info->changed = 1))
		info->minus = 1;
	else if (str[i] == '+' && i++ && (info->changed = 1))
		info->plus = 1;
	else if (str[i] == ' ' && (info->changed = 1))
	{
		info->space = 1;
		if (str[i + 1] == ' ')
			while (str[i] == ' ')
				i++;
		else
			i++;
	}
	else if (str[i] == '#' && i++ && (info->changed = 1))
		info->hash = 1;
	else if (str[i] == '0' && i++ && (info->changed = 1))
		info->zero = 1;
	return (i);
}

int		parse_width(t_info *info, const char *str, int i)
{
	if (str[i] == '*' && i++ && (info->changed = 1))
	{
		info->star = 1;
		if (info->dot == 0)
			info->width = va_arg(info->va_list, int);
		else if (info->dot == 1)
			info->precision = va_arg(info->va_list, int);
	}
	else if (str[i] > '0' && str[i] <= '9' && (info->changed = 1))
	{
		info->width = count_stoi(&str[i]);
		i += count_width(&str[i]);
	}
	else if (str[i] == '.' && i++ && (info->changed = 1))
	{
		info->dot = 1;
		info->precision = count_stoi(&str[i]);
		i += count_width(&str[i]);
	}
	return (i);
}

int		parse_length(t_info *info, const char *str, int i)
{
	if (str[i] == 'l' && i++ && (info->changed = 1))
		info->cast = _LONG;
	else if (str[i] == 'h' && str[i + 1] == 'h' && i++ && i++ && (info->changed = 1))
		info->cast = _UCHAR;
	else if (str[i] == 'h' && i++ && (info->changed = 1))
		info->cast = _USHORTINT;
	else if (str[i] == 'l' && str[i + 1] == 'l' && i++ && i++ && (info->changed = 1))
		info->cast = _LONGLONG;
	else if (str[i] == 'j' && i++ && (info->changed = 1))
		info->cast = _UINTMAXT;
	else if (str[i] == 'z' && i++ && (info->changed = 1))
		info->cast = _SIZET;
	return (i);
}

int		deal_with_flags(t_info *info, const char *str, int i)
{
	while (!is_flag(str[i]))
	{
		info->changed = 0;
		i = parse_flags(info, str, i);
		if (info->changed)
			continue ;
		i = parse_width(info, str, i);
		if (info->changed)
			continue ;
		i = parse_length(info, str, i);
		if (info->changed)
			continue ;
		if (str[i] == '%')
			return (i);
		else if (someth_else(str[i]) && str[i - 1] != '%')
		{
			info->smt = 1;
			if (info->width || info->minus)
				return (i);
			return (--i);
		}
		else
			i++;
	}
	return (i);
}

int		deal_with_types(t_info *info, s_num n, const char *str, int i)
{
	if (str[i] == 'd' || str[i] == 'D' || str[i] == 'i')
		return (print_d(info, n, str, i));
	else if (str[i] == 'u' || str[i] == 'U')
		return (print_u(info, n, str, i));
	else if (str[i] == 'o')
		return (print_o(info, n, str, i));
	else if (str[i] == 'O')
		return (print_lo(info, n, str, i));
	else if (str[i] == 'x')
		return (print_x(info, n, str, i));
	else if (str[i] == 'X')
		return (print_lx(info, n, str, i));
	else if (str[i] == 'p')
		return (print_p(info, n, str, i));
	else if (str[i] == 'S' || (str[i] == 's' && info->cast == _LONG))
		return (print_ls(info, n, str, i));
	else if (str[i] == 's')
		return (print_s(info, n, str, i));
	else if (str[i] == 'c' || str[i] == 'C')
		return (print_c(info, n, str, i));
	else if (str[i] == '%')
		return (print_percent(info, n, str, i));
	else if (info->smt)
		return (print_else(info, n, str, i));
	return (i);
}

int		parse_argument(const char *str, t_info *info)
{
	int		i;
	s_num	n;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (info->res);
			i++;
			init_flags(info);
			i = deal_with_flags(info, str, i);
			i = deal_with_types(info, n, str, i);
		}
		else
		{
			write(1, &str[i], 1);
			info->res += 1;
		}
		i++;
	}
	return (info->res);
}

int		ft_printf(const char *msg, ...)
{
	t_info	info;

	info.res = 0;
	init_flags(&info);
	va_start(info.va_list, msg);
	info.res = parse_argument(msg, &info);
	va_end(info.va_list);
	return (info.res);
}
