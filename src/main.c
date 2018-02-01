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

void	ft_putaddr_fd(void *str)
{
	long int			div;
	char				temp;
	unsigned long int	n;

	n = (unsigned long int)str;
	div = 16;
	write(1, "0x", 2);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(1, &temp, 1);
		}
		else
			write(1, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	init(t_info *info)
{
	info->res = 0;
	info->minus = 0;
	info->sign = 0;
	info->zero = 0;
	info->resh = 0;
	info->space = 0;
	info->width = 0;
	info->prec = 0;
	info->size = 0;
	info->bukva = 0;
}

int		manage_signs(const char *str, int i, t_info *info)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == '#'
		|| str[i] == ' ')
	{
		if (str[i] == '-' && !(info->zero = 0))
			info->minus = 1;
		else if (str[i] == '+')
			info->sign = 1;
		else if (str[i] == '0' && !info->minus)
			info->zero = 1;
		else if (str[i] == '#')
			info->resh = 1;
		else if (str[i] == ' ' && info->sign != 1)
			info->space = 1;
		i++;
	}
	return (i);
}

int		manage_digits(const char *str, int i, t_info *info)
{
	if (str[i] == '.')
	{
		info->prec = 0;
		i++;
		if (str[i] == '*')
		{
			info->prec = va_arg(info->list, int);
			if (info->prec < 0)
				info->prec = -1;
			i++;
		}
		else
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				info->prec = info->prec * 10 + str[i] - '0';
				i++;
			}
		}
	}
	return (i);
}

int		manage_width(const char *str, int i, t_info *info)
{
	if (str[i] == '*')
	{
		info->width = va_arg(info->list, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->minus = 1;
		}
		i++;
	}
	else
	{
		while ((str[i] >= '0' && str[i] <= '9'))
		{
			info->width = info->width * 10 + str[i] - '0';
			i++;
		}
	}
	i = manage_digits(str, i, info);
	return (i);
}

int			count_char(const char *str, int i, t_info *info, char c)
{
	int cunt;

	cunt = 0;
	while (str[i] == c)
	{
		cunt++;
		i++;
	}
	if (cunt % 2)
		info->size = c == 'l' ? 3 : 2;
	else
		info->size = c == 'l' ? 4 : 1;
	return (i - 1);
}

int		manage_letters(const char *str, int i, t_info *info)
{
	while (str[i] == 'j' || str[i] == 'l' || str[i] == 'h' || str[i] == 'z')
	{
		if (str[i] == 'z')
			info->size = 6;
		else if (str[i] == 'j' && info->size < 5)
			info->size = 5;
		else if (str[i] == 'l' && info->size < 4)
			i = count_char(str, i, info, 'l');
		else if (str[i] == 'h' && info->size < 2)
			i = count_char(str, i, info, 'h');
		i++;
	}
	return (i);
}

void		f_ten(intmax_t value, char *str, intmax_t base, int *i)
{
	char	*tmp;

	tmp = "0123456789ABCDEF";
	if (value <= -base || value >= base)
		f_ten(value / base, str, base, i);
	str[(*i)++] = tmp[A(value % base)];
}

char		*ft_itoaint(intmax_t value)
{
	int				i;
	char			*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 32)))
		return (0);
	if (value < 0)
		str[i++] = '-';
	f_ten(value, str, 10, &i);
	str[i] = '\0';
	return (str);
}

char		*ft_mod_resh(char *str, t_info *info)
{
	char *tmp;

	tmp = str;
	if (info->bukva == 'o' || info->bukva == 'O')
		str = ft_strjoin("0", str);
	else if (info->bukva == 'x' && str[0])
		str = ft_strjoin("0x", str);
	else if (info->bukva == 'X' && str[0])
		str = ft_strjoin("0X", str);
	else
		return (str);
	free(tmp);
	return (str);
}

char		*ft_mod_sign(char *str, t_info *info)
{
	char *tmp;

	if (str[0] != '-' && str[0])
	{
		tmp = str;
		if (info->sign)
			str = ft_strjoin("+", str);
		else if (info->space)
			str = ft_strjoin(" ", str);
		else
			return (str);
		free(tmp);
	}
	return (str);
}

char		*pre_join(char *str, int len, char *rem, int pl)
{
	char *help;
	char *tmp;

	help = ft_strnew(len);
	ft_memset(help, '0', len);
	tmp = str;
	str = ft_strjoin(help, str + pl);
	free(tmp);
	free(help);
	tmp = str;
	str = ft_strjoin(rem, str);
	free(tmp);
	return (str);
}

void		prec_dig_help(char **str, t_info *info, char *rem)
{
	int len;

	rem = ft_strsub(*str, 0, 2);
	if ((len = ft_strlen(*str + 2)) < info->prec)
		*str = pre_join(*str, info->prec - len, rem, 2);
	free(rem);
}

char		*ft_prec_dig(char *str, t_info *info)
{
	char	*tmp;
	char	*rem;
	int		len;

	rem = NULL;
	tmp = NULL;
	if (info->sign || info->space || str[0] == '-')
	{
		rem = ft_strnew(1);
		rem[0] = str[0];
		if ((len = ft_strlen(str + 1)) < info->prec)
			str = pre_join(str, info->prec - len, rem, 1);
		free(rem);
	}
	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		prec_dig_help(&str, info, rem);
	else if (info->prec > (len = ft_strlen(str)))
		str = pre_join(str, info->prec - len, "", 0);
	return (str);
}

char		*ft_mod_prec(char *str, t_info *info)
{
	char *tmp;

	if (info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i' ||
		info->bukva == 'o' || info->bukva == 'O' || info->bukva == 'u' ||
		info->bukva == 'U' || info->bukva == 'x' || info->bukva == 'X' ||
		info->bukva == 'p')
		str = ft_prec_dig(str, info);
	else if (info->bukva == 's' || info->bukva == 'S')
	{
		if ((int)ft_strlen(str) > info->prec)
		{
			tmp = str;
			str = ft_strsub(str, 0, info->prec);
			free(tmp);
		}
	}
	return (str);
}

void	ft_width_help(char **str, t_info *info, int len)
{
	char	*tmp;
	char	*buf;

	tmp = ft_strnew(info->width - len);
	ft_memset(tmp, ' ', info->width - len);
	buf = *str;
	if (info->minus > 0)
		*str = ft_strjoin(*str, tmp);
	else
		*str = ft_strjoin(tmp, *str);
	free(tmp);
	free(buf);
}

char	*ft_width(char *str, t_info *info)
{
	int		len;
	int		tm;

	if ((len = ft_strlen(str)) < info->width)
	{
		if (info->prec < 0 && info->minus != 1 && info->zero == 1)
		{
			if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
				info->width -= 1;
			if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
				info->width -= 2;
			tm = info->prec;
			info->prec = info->width;
			str = ft_mod_prec(str, info);
			info->prec = tm;
			return (str);
		}
		else
			ft_width_help(&str, info, len);
	}
	return (str);
}


void		ft_mod(char *str, t_info *info, int un)
{
	if (info->prec == 0 && info->bukva != 'p' && (str[0] == '0' || !str))
	{
		if (str)
			free(str);
		str = ft_strnew(0);
	}
	if (un && info->resh && str[0] != '0')
		str = ft_mod_resh(str, info);
	else if (un == 0 && str[0])
		str = ft_mod_sign(str, info);
	if (info->prec > 0)
		str = ft_mod_prec(str, info);
	if (info->width > 0)
		str = ft_width(str, info);
	info->res += write(1, str, ft_strlen(str));
	free(str);
}

void	cast_int(t_info *info)
{
	intmax_t ret;

	if (info->size == 3 || info->bukva == 'D')
		ret = va_arg(info->list, long);
	else if (info->size == 6)
		ret = va_arg(info->list, size_t);
	else if (info->size == 5)
		ret = va_arg(info->list, intmax_t);
	else if (info->size == 4)
		ret = va_arg(info->list, long long);
	else if (info->size == 2)
		ret = (short)va_arg(info->list, int);
	else if (info->size == 1)
		ret = (signed char)va_arg(info->list, int);
	else
		ret = va_arg(info->list, int);
	ft_mod(ft_itoaint(ret), info, 0);
}

size_t		ft_len_num(unsigned long long value, int base)
{
	int	count;

	count = 0;
	if (value <= 0)
		count++;
	while (value != 0)
	{
		count++;
		value /= base;
	}
	return (count);
}

char		*ft_lower_case(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

char		*ft_itoa_base(unsigned long long value, int base, int flag)
{
	char	*itoa;
	char	*box;
	size_t	len;

	box = "0123456789ABCDEF";
	len = ft_len_num(value, base);
	itoa = ft_strnew(len);
	if (itoa)
	{
		itoa[len] = '\0';
		if (value == 0)
			itoa[0] = '0';
		while (value != 0)
		{
			itoa[--len] = box[(value % base)];
			value = value / base;
		}
		if (flag == 0)
			itoa = ft_lower_case(itoa);
	}
	return (itoa);
}

void	cast_unsigned(t_info *info)
{
	uintmax_t ret;

	if (info->size == 3 || info->bukva == 'U' || info->bukva == 'O')
		ret = va_arg(info->list, unsigned long);
	else if (info->size == 6)
		ret = va_arg(info->list, size_t);
	else if (info->size == 5)
		ret = va_arg(info->list, uintmax_t);
	else if (info->size == 4)
		ret = va_arg(info->list, unsigned long long);
	else if (info->size == 2)
		ret = (unsigned short)va_arg(info->list, unsigned int);
	else if (info->size == 1)
		ret = (unsigned char)va_arg(info->list, unsigned int);
	else
		ret = va_arg(info->list, unsigned int);
	if (info->bukva == 'u' || info->bukva == 'U')
		ft_mod(ft_itoa_base(ret, 10, 0), info, 1);
	else if (info->bukva == 'o' || info->bukva == 'O')
		ft_mod(ft_itoa_base(ret, 8, 0), info, 1);
	else
		ft_mod(ft_itoa_base(ret, 16, info->bukva == 'X' ? 1 : 0), info, 1);
}

int				ft_take_wlen(const uint32_t symbol)
{
	int			size;

	size = 0;
	if (symbol <= BIT7)
		size += 1;
	else if (symbol <= BIT11)
		size += 2;
	else if (symbol <= BIT16)
		size += 3;
	else if (symbol <= BIT21)
		size += 4;
	return (size);
}

char			*ft_parse_wchar(const uint32_t symbol, int p)
{
	char		*rt;

	rt = ft_strnew(4);
	if (symbol <= BIT7 && p >= 1)
		rt[0] = symbol;
	else if (symbol <= BIT11 && p >= 2)
	{
		rt[0] = ((symbol & 1984) >> 6) | 192;
		rt[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16 && p >= 3)
	{
		rt[0] = ((symbol & 61440) >> 12) | 224;
		rt[1] = ((symbol & 4032) >> 6) | 128;
		rt[2] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT21 && p >= 4)
	{
		rt[0] = ((symbol & 1835008) >> 18) | 240;
		rt[1] = ((symbol & 258048) >> 12) | 128;
		rt[2] = ((symbol & 4032) >> 6) | 128;
		rt[3] = (symbol & 63) | 128;
	}
	return (rt);
}

void		ft_wputstr(char **d, t_info *info)
{
	int		a;
	int		j;

	a = 0;
	while (d[a])
	{
		j = 0;
		while (d[a][j])
		{
			info->res += write(1, &d[a][j], 1);
			j++;
		}
		a++;
	}
}

int			ft_check_len_wch(char **data)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = 0;
	while (data[i])
	{
		tmp += ft_strlen(data[i]);
		i++;
	}
	return (tmp);
}

void		ft_place_char(int size, char c, t_info *info)
{
	int		i;

	i = 0;
	while (i < size)
	{
		info->res += write(1, &c, 1);
		i++;
	}
}

void			ft_make_width(char **data, t_info *info)
{
	int i;

	i = 0;
	if (info->minus == 1)
	{
		ft_wputstr(data, info);
		ft_place_char(info->width - ft_check_len_wch(data), ' ', info);
	}
	else if (info->zero == 1)
	{
		ft_place_char(info->width - ft_check_len_wch(data), '0', info);
		ft_wputstr(data, info);
	}
	else
	{
		ft_place_char(info->width - ft_check_len_wch(data), ' ', info);
		ft_wputstr(data, info);
	}
	while (data[i])
		free(data[i++]);
	free(data);
}

void			ft_widestr(wchar_t *d, t_info *info)
{
	int			i;
	int			p;
	char		**s;

	i = 0;
	while (d[i])
		i++;
	s = (char**)malloc(sizeof(char*) * (i + 1));
	s[i] = NULL;
	i = 0;
	p = info->prec;
	while (d[i])
	{
		if (info->prec < 0)
			p = 4;
		s[i] = ft_parse_wchar(d[i], p);
		p -= ft_take_wlen(d[i]);
		i++;
	}
	ft_make_width(s, info);
}

void		ft_modchar_help(char *str, t_info *info, char *tmp, int len)
{
	tmp = ft_strnew(info->width - len);
	if (info->zero > 0 && info->space <= 0)
		ft_memset(tmp, '0', info->width - len);
	else
		ft_memset(tmp, ' ', info->width - len);
	if (info->minus > 0)
	{
		info->res += write(1, str, len);
		info->res += write(1, tmp, info->width - len);
	}
	else
	{
		info->res += write(1, tmp, info->width - len);
		info->res += write(1, str, len);
	}
	free(tmp);
}

void		ft_modchar(char *str, t_info *info)
{
	char	*tmp;
	int		len;

	if (info->prec != -1 && info->prec < (int)ft_strlen(str))
	{
		tmp = str;
		str = ft_strsub(str, 0, info->prec);
		free(tmp);
	}
	len = ft_strlen(str);
	if (info->width > len)
		ft_modchar_help(str, info, tmp, len);
	else
		info->res += write(1, str, len);
	free(str);
}

void		ft_char(t_info *info)
{
	int			c;
	char		ch;

	ch = ' ';
	c = va_arg(info->list, int);
	if (info->width > 0)
	{
		if (info->zero == 1)
			ch = '0';
		if (info->minus == 1)
		{
			info->res += write(1, &c, 1);
			ft_place_char(info->width - 1, ch, info);
		}
		else
		{
			ft_place_char(info->width - 1, ch, info);
			info->res += write(1, &c, 1);
		}
	}
	else
		info->res += write(1, &c, 1);
}

void	cast_char(t_info *info)
{
	char	*str;
	wchar_t *wstr;

	if (info->bukva == 'S' || (info->bukva == 's' && info->size == 3))
	{
		if (!(wstr = va_arg(info->list, wchar_t*)))
			ft_widestr(L"(null)", info);
		else
			ft_widestr(wstr, info);
	}
	else
	{
		str = NULL;
		if (info->bukva == 's')
		{
			str = va_arg(info->list, char*);
			if (!str)
				str = ft_strdup("(null)");
			else
				str = ft_strdup(str);
			ft_modchar(str, info);
		}
		else if (info->bukva == 'c' || info->bukva == 'C')
			ft_char(info);
	}
}

void	cast_pointer(t_info *info)
{
	uintmax_t	ret;
	char		*str;
	char		*tmp;
	char		*buf;

	str = ft_strnew(2);
	str[0] = '0';
	str[1] = 'x';
	ret = (uintmax_t)va_arg(info->list, void*);
	if (ret == 0 && info->prec != -1)
		buf = str;
	else
	{
		tmp = ft_itoa_base(ret, 16, 0);
		buf = ft_strjoin(str, tmp);
		free(tmp);
		free(str);
	}
	ft_mod(buf, info, 1);
}

void	ft_cast(t_info *info)
{
	if (info->bukva == 's' || info->bukva == 'S' ||
		info->bukva == 'c' || info->bukva == 'C')
		cast_char(info);
	else if (info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i')
		cast_int(info);
	else if (info->bukva == 'o' || info->bukva == 'O' || info->bukva == 'u'
		|| info->bukva == 'U' || info->bukva == 'x' || info->bukva == 'X')
		cast_unsigned(info);
	else if (info->bukva == 'p')
		cast_pointer(info);
}

void		write_width(t_info *info)
{
	char	*str;

	if (info->bukva == '\0')
		return ;
	else if (info->width <= 0)
		info->res += write(1, &info->bukva, 1);
	else
	{
		str = ft_strnew(info->width);
		if (info->zero > 0)
			ft_memset(str, '0', info->width);
		else
			ft_memset(str, ' ', info->width);
		if (info->minus > 0)
			str[0] = info->bukva;
		else
			str[info->width - 1] = info->bukva;
		info->res += write(1, str, info->width);
		free(str);
	}
}

void	parse_next(t_info *info)
{
	if (info->bukva == 's' || info->bukva == 'S' || info->bukva == 'o'
		|| info->bukva == 'O' || info->bukva == 'u' || info->bukva == 'U'
		|| info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i'
		|| info->bukva == 'x' || info->bukva == 'X' || info->bukva == 'c'
		|| info->bukva == 'C' || info->bukva == 'p')
		ft_cast(info);
	else
		write_width(info);
}

int		sort_param(const char *str, t_info *info, int i)
{
	int	tmp;

	while (1)
	{
		tmp = i;
		i = manage_signs(str, i, info);
		i = manage_width(str, i, info);
		i = manage_letters(str, i, info);
		if (tmp == i)
			break ;
	}
	info->bukva = str[i];
	parse_next(info);
	if (!str[i])
		return (i);
	return (i + 1);
}

int		parse_argument(const char *str, t_info *info)
{
	int		i;
	
	i = 0;
	init(info);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' && (i += 2))
				info->res += write(1, "%", 1);
			else
				i = sort_param(str, info, ++i);
		}
		else
		{
			info->res += write(1, &str[i], 1);
			i++;
		}
	}
	return (info->res);
}

int		ft_printf(const char *msg, ...)
{
	int		res;
	t_info	info;

	res = 0;
	va_start(info.list, msg);
	res = parse_argument(msg, &info);
	va_end(info.list);
	return (res);
}
