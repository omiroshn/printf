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

int		deal_with_flags(t_info *info, const char *str, int i)
{
	while (!is_flag(str[i]))
	{
		if (str[i] == '-' && i++)
			info->minus = 1;
		else if (str[i] == '+' && i++)
			info->plus = 1;
		else if (str[i] == ' ')
		{
			info->space = 1;
			if (str[i + 1] == ' ')
				while (str[i] == ' ')
					i++;
			else
				i++;
		}
		else if (str[i] == '#' && i++)
			info->hash = 1;
		else if (str[i] == '0' && i++)
			info->zero = 1;
		else if (str[i] == '*' && i++)
		{
			info->star = 1;
			if (info->dot == 0)
				info->width = va_arg(info->va_list, int);
			else if (info->dot == 1)
				info->precision = va_arg(info->va_list, int);
		}
		else if (str[i] > '0' && str[i] <= '9')
		{
			info->width = count_stoi(&str[i]);
			i += count_width(&str[i]);
		}
		else if (str[i] == '.' && i++)
		{
			info->dot = 1;
			info->precision = count_stoi(&str[i]);
			i += count_width(&str[i]);
		}
		else if (str[i] == 'l' && i++)
			info->cast = _LONG;
		else if (str[i] == 'h' && str[i + 1] == 'h' && i++ && i++)
			info->cast = _UCHAR;
		else if (str[i] == 'h' && i++)
			info->cast = _USHORTINT;
		else if (str[i] == 'l' && str[i + 1] == 'l' && i++ && i++)
			info->cast = _LONGLONG;
		else if (str[i] == 'j' && i++)
			info->cast = _UINTMAXT;
		else if (str[i] == 'z' && i++)
			info->cast = _SIZET;
		else if (str[i] == '%')
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

uintmax_t	ft_cast_hex(uintmax_t temp, t_info *info, const char *str, int i)
{
	if (info->cast == _LONG || str[i] == 'U' || str[i] == 'O')
		temp = va_arg(info->va_list, unsigned long);
	else if (info->cast == _UCHAR)
		temp = (unsigned char)va_arg(info->va_list, int);
	else if (info->cast == _USHORTINT)
		temp = (unsigned short)va_arg(info->va_list, int);
	else if (info->cast == _LONGLONG)
		temp = va_arg(info->va_list, unsigned long long);
	else if (info->cast == _UINTMAXT)
		temp = va_arg(info->va_list, uintmax_t);
	else if (info->cast == _SIZET)
		temp = va_arg(info->va_list, size_t);
	else
		temp = va_arg(info->va_list, unsigned int);
	return (temp);
}

intmax_t	ft_cast_int(intmax_t temp, t_info *info, const char *str, int i)
{
	if (info->cast == _LONG || str[i] == 'D')
		temp = va_arg(info->va_list, long);
	else if (info->cast == _UCHAR)
		temp = (signed char)va_arg(info->va_list, int);
	else if (info->cast == _USHORTINT)
		temp = (short)va_arg(info->va_list, int);
	else if (info->cast == _LONGLONG)
		temp = va_arg(info->va_list, long long);
	else if (info->cast == _UINTMAXT)
		temp = va_arg(info->va_list, intmax_t);
	else if (info->cast == _SIZET)
		temp = va_arg(info->va_list, size_t);
	else
		temp = va_arg(info->va_list, int);
	return (temp);
}

struct my_num
{
	intmax_t	imaxt;
	intmax_t	uimaxt;
	wint_t		*swit;
	wint_t		cwit;
	int			prec;
	int			wid;
	char		*s;
	char		*s2;
};

int		deal_with_types(t_info *info, const char *str, int i)
{
	struct my_num n;

	if (str[i] == 'd' || str[i] == 'D' || str[i] == 'i')
	{
		n.imaxt = ft_cast_int(n.imaxt, info, str, i);
		n.prec = info->precision;
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (info->width > 0)
			info->width -= ft_intlen(n.imaxt);
		if (info->width && n.imaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_intlen(n.imaxt);
			n.imaxt < 0 ? info->precision++ : 0;
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if ((n.imaxt >= 0 && info->plus)
			|| (n.imaxt >= 0 && info->space && info->zero && info->width > 0))
			info->width--;
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if ((n.imaxt >= 0 && info->space && !info->width)
			|| (n.imaxt >= 0 && info->space && info->zero && info->width > 0))
		{
			write(1, " ", 1);
			info->res++;
		}
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (n.imaxt >= 0 && info->plus)
		{
			write(1, "+", 1);
			info->res++;
		}
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (n.imaxt < 0)
			{
				write(1, "-", 1);
				n.imaxt *= -1;
				info->res++;
			}
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (n.imaxt < 0 && n.imaxt != -9223372036854775808U)
		{
			write(1, "-", 1);
			n.imaxt *= -1;
			info->res++;
		}
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.imaxt == 0 && n.prec == 0 && info->dot)
			return (i);
		n.s = ft_itoa(n.imaxt);
		ft_putstr(n.s);
		info->res += ft_intlen(n.imaxt);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'u' || str[i] == 'U')
	{
		n.imaxt = ft_cast_hex(n.imaxt, info, str, i);
		n.prec = info->precision;
		if (info->width > 0)
			info->width -= ft_intlen_u(n.imaxt);
		if (info->width && n.imaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_intlen_u(n.imaxt);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
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
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.imaxt == 0 && n.prec == 0 && info->dot)
			return (i);
		n.s = ft_itoa_u(n.imaxt);
		ft_putstr(n.s);
		info->res += ft_intlen_u(n.imaxt);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'o')
	{
		n.uimaxt = ft_cast_hex(n.uimaxt, info, str, i);
		n.s = ft_itoa_base(n.uimaxt, 8, 0);
		n.prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(n.s);
		if (info->hash && n.uimaxt != 0 && !info->precision)
		{
			info->width -= 1;
			info->res += 1;
		}
		if (info->width && n.uimaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(n.s);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((!info->minus && info->zero && info->precision <= 0) ||
			(!info->minus && info->dot && info->precision))
		{
			if (info->hash && n.uimaxt != 0 && !info->dot)
				ft_putstr("0");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((info->hash && n.uimaxt != 0 && !info->zero && info->precision == 0)
			|| (info->hash && n.uimaxt != 0 && info->minus && info->precision == 0))
		{
			n.s2 = n.s;
			n.s = ft_strjoin("0", n.s2);
			info->res -= 1;
			free(n.s2);
		}
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.uimaxt == 0 && n.prec == 0 && info->dot && !info->hash)
			return (i);
		ft_putstr(n.s);
		info->res += ft_strlen(n.s);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'O')
	{
		n.uimaxt = ft_cast_hex(n.uimaxt, info, str, i);
		n.s = ft_itoa_base(n.uimaxt, 8, 1);
		n.prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(n.s);
		if (info->hash && n.uimaxt != 0 && !info->precision)
		{
			info->width -= 1;
			info->res += 1;
		}
		if (info->width && n.uimaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(n.s);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((!info->minus && info->zero && info->precision <= 0) ||
			(!info->minus && info->dot && info->precision))
		{
			if (info->hash && n.uimaxt != 0 && !info->dot)
				ft_putstr("0");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((info->hash && n.uimaxt != 0 && !info->zero && info->precision == 0)
			|| (info->hash && n.uimaxt != 0 && info->minus && info->precision == 0))
		{
			n.s2 = n.s;
			n.s = ft_strjoin("0", n.s2);
			info->res -= 1;
			free(n.s2);
		}
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.uimaxt == 0 && n.prec == 0 && info->dot && !info->hash)
			return (i);
		ft_putstr(n.s);
		info->res += ft_strlen(n.s);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == 'x')
	{
		n.uimaxt = ft_cast_hex(n.uimaxt, info, str, i);
		n.s = ft_itoa_base(n.uimaxt, 16, 0);
		n.prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(n.s);
		if (info->hash && n.uimaxt != 0)
		{
			info->width -= 2;
			info->res += 2;
		}
		if (info->width && n.uimaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(n.s);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((!info->minus && info->zero && info->precision <= 0) ||
			(!info->minus && info->dot && info->precision))
		{
			if (info->hash && n.uimaxt != 0)
				ft_putstr("0x");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.uimaxt == 0 && n.prec == 0 && info->dot)
			return (i);
		if ((info->hash && n.uimaxt != 0 && !info->zero && !info->dot)
			|| (info->hash && n.uimaxt != 0 && info->minus && !info->dot))
		{
			n.s2 = n.s;
			n.s = ft_strjoin("0x", n.s2);
			info->res -= 2;
			free(n.s2);
		}
		ft_putstr(n.s);
		info->res += ft_strlen(n.s);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'X')
	{
		n.uimaxt = ft_cast_hex(n.uimaxt, info, str, i);
		n.s = ft_itoa_base(n.uimaxt, 16, 1);
		n.prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(n.s);
		if (info->hash && n.uimaxt != 0)
		{
			info->width -= 2;
			info->res += 2;
		}
		if (info->width && n.uimaxt == 0 && n.prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(n.s);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if ((!info->minus && info->zero && info->precision <= 0) ||
			(!info->minus && info->dot && info->precision))
		{
			if (info->hash && n.uimaxt != 0)
				ft_putstr("0X");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (n.uimaxt == 0 && n.prec == 0 && info->dot)
			return (i);
		if ((info->hash && n.uimaxt != 0 && !info->zero && !info->dot)
			|| (info->hash && n.uimaxt != 0 && info->minus && !info->dot))
		{
			n.s2 = n.s;
			n.s = ft_strjoin("0X", n.s2);
			info->res -= 2;
			free(n.s2);
		}
		ft_putstr(n.s);
		info->res += ft_strlen(n.s);
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'p')
	{
		n.uimaxt = va_arg(info->va_list, uintmax_t);
		n.s = ft_itoa_base(n.uimaxt, 16, 0);
		if (info->width > 0)
			info->width -= ft_strlen(n.s) + 2;
		if (info->width && n.uimaxt == 0 && info->precision == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			n.uimaxt != 0 ? info->precision -= ft_strlen(n.s) : 0;
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		n.wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (n.uimaxt == 0 && info->dot)
		{
			ft_putstr("0x");
			while (info->precision-- > 0)
				write(1, "0", 1);
			info->res += 2;
			return (i);
		}
		ft_putstr("0x");
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (!info->minus && info->zero && info->precision <= 0)
			while (info->width-- > 0)
				write(1, "0", 1);
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		ft_putstr(n.s);
		info->res += ft_strlen(n.s) + 2;
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
		free(n.s);
	}
	else if (str[i] == 'S' || (str[i] == 's' && info->cast == _LONG))
	{
		if (!(n.swit = va_arg(info->va_list, wint_t*)))
			n.swit = L"(null)";
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (info->width > 0 && ft_ustrlen(n.swit) > info->precision)
		{
			if (info->precision >= 0 && info->dot)
				info->width -= ft_spreclen(n.swit, info->precision);
			else
				info->width -= ft_ustrlen(n.swit);
		}
		if (info->precision > 0 && ft_ustrlen(n.swit) < info->precision)
			info->width -= ft_ustrlen(n.swit);
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
		if (info->precision >= 0 && ft_ustrlen(n.swit) > info->precision && info->dot)
			info->res += ft_putustrl(n.swit, info->precision);
		else
		{
			ft_putustr(n.swit);
			info->res += ft_ustrlen(n.swit);
		}
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == 's')
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
	}
	else if (str[i] == 'c' || str[i] == 'C')
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
	}
	else if (str[i] == '%')
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
	}
	else if (info->smt)
	{
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (info->width > 0)
		{
			info->width -= 1;
			info->res += info->width;
		}
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
		if (!info->space)
		{
			write(1, &str[i], 1);
			info->res++;
		}
		if (info->minus)
			while (n.wid-- > 0)
				write(1, " ", 1);
	}
	return (i);
}

int		parse_argument(const char *str, t_info *info)
{
	int i;
	
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
			i = deal_with_types(info, str, i);
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
