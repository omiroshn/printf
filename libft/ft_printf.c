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

// void	ft_putaddr_fd(void *str)
// {
// 	long int			div;
// 	char				temp;
// 	unsigned long int	n;

// 	n = (unsigned long int)str;
// 	div = 16;
// 	write(1, "0x", 2);
// 	while (n / div >= 16)
// 		div *= 16;
// 	while (div > 0)
// 	{
// 		temp = '0' + n / div;
// 		if (temp > '9')
// 		{
// 			temp += 39;
// 			write(1, &temp, 1);
// 		}
// 		else
// 			write(1, &temp, 1);
// 		n %= div;
// 		div /= 16;
// 	}
// }

// void	init(t_info *info)
// {
// 	info->res = 0;
// 	info->minus = 0;
// 	info->sign = 0;
// 	info->zero = 0;
// 	info->resh = 0;
// 	info->space = 0;
// 	info->width = 0;
// 	info->prec = 0;
// 	info->size = 0;
// 	info->bukva = 0;
// }

// int		manage_signs(const char *str, int i, t_info *info)
// {
// 	while (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == '#'
// 		|| str[i] == ' ')
// 	{
// 		if (str[i] == '-' && !(info->zero = 0))
// 			info->minus = 1;
// 		else if (str[i] == '+')
// 			info->sign = 1;
// 		else if (str[i] == '0' && !info->minus)
// 			info->zero = 1;
// 		else if (str[i] == '#')
// 			info->resh = 1;
// 		else if (str[i] == ' ' && info->sign != 1)
// 			info->space = 1;
// 		i++;
// 	}
// 	return (i);
// }

// int		manage_digits(const char *str, int i, t_info *info)
// {
// 	if (str[i] == '.')
// 	{
// 		info->prec = 0;
// 		i++;
// 		if (str[i] == '*')
// 		{
// 			info->prec = va_arg(info->list, int);
// 			if (info->prec < 0)
// 				info->prec = -1;
// 			i++;
// 		}
// 		else
// 		{
// 			while (str[i] >= '0' && str[i] <= '9')
// 			{
// 				info->prec = info->prec * 10 + str[i] - '0';
// 				i++;
// 			}
// 		}
// 	}
// 	return (i);
// }

// int		manage_width(const char *str, int i, t_info *info)
// {
// 	if (str[i] == '*')
// 	{
// 		info->width = va_arg(info->list, int);
// 		if (info->width < 0)
// 		{
// 			info->width *= -1;
// 			info->minus = 1;
// 		}
// 		i++;
// 	}
// 	else
// 	{
// 		while ((str[i] >= '0' && str[i] <= '9'))
// 		{
// 			info->width = info->width * 10 + str[i] - '0';
// 			i++;
// 		}
// 	}
// 	i = manage_digits(str, i, info);
// 	return (i);
// }

// int			count_char(const char *str, int i, t_info *info, char c)
// {
// 	int cunt;

// 	cunt = 0;
// 	while (str[i] == c)
// 	{
// 		cunt++;
// 		i++;
// 	}
// 	if (cunt % 2)
// 		info->size = c == 'l' ? 3 : 2;
// 	else
// 		info->size = c == 'l' ? 4 : 1;
// 	return (i - 1);
// }

// int		manage_letters(const char *str, int i, t_info *info)
// {
// 	while (str[i] == 'j' || str[i] == 'l' || str[i] == 'h' || str[i] == 'z')
// 	{
// 		if (str[i] == 'z')
// 			info->size = 6;
// 		else if (str[i] == 'j' && info->size < 5)
// 			info->size = 5;
// 		else if (str[i] == 'l' && info->size < 4)
// 			i = count_char(str, i, info, 'l');
// 		else if (str[i] == 'h' && info->size < 2)
// 			i = count_char(str, i, info, 'h');
// 		i++;
// 	}
// 	return (i);
// }

// void		f_ten(intmax_t value, char *str, intmax_t base, int *i)
// {
// 	char	*tmp;

// 	tmp = "0123456789ABCDEF";
// 	if (value <= -base || value >= base)
// 		f_ten(value / base, str, base, i);
// 	str[(*i)++] = tmp[A(value % base)];
// }

// char		*ft_itoaint(intmax_t value)
// {
// 	int				i;
// 	char			*str;

// 	i = 0;
// 	if (!(str = (char*)malloc(sizeof(char) * 32)))
// 		return (0);
// 	if (value < 0)
// 		str[i++] = '-';
// 	f_ten(value, str, 10, &i);
// 	str[i] = '\0';
// 	return (str);
// }

// char		*ft_mod_resh(char *str, t_info *info)
// {
// 	char *tmp;

// 	tmp = str;
// 	if (info->bukva == 'o' || info->bukva == 'O')
// 		str = ft_strjoin("0", str);
// 	else if (info->bukva == 'x' && str[0])
// 		str = ft_strjoin("0x", str);
// 	else if (info->bukva == 'X' && str[0])
// 		str = ft_strjoin("0X", str);
// 	else
// 		return (str);
// 	free(tmp);
// 	return (str);
// }

// char		*ft_mod_sign(char *str, t_info *info)
// {
// 	char *tmp;

// 	if (str[0] != '-' && str[0])
// 	{
// 		tmp = str;
// 		if (info->sign)
// 			str = ft_strjoin("+", str);
// 		else if (info->space)
// 			str = ft_strjoin(" ", str);
// 		else
// 			return (str);
// 		free(tmp);
// 	}
// 	return (str);
// }

// char		*pre_join(char *str, int len, char *rem, int pl)
// {
// 	char *help;
// 	char *tmp;

// 	help = ft_strnew(len);
// 	ft_memset(help, '0', len);
// 	tmp = str;
// 	str = ft_strjoin(help, str + pl);
// 	free(tmp);
// 	free(help);
// 	tmp = str;
// 	str = ft_strjoin(rem, str);
// 	free(tmp);
// 	return (str);
// }

// void		prec_dig_help(char **str, t_info *info, char *rem)
// {
// 	int len;

// 	rem = ft_strsub(*str, 0, 2);
// 	if ((len = ft_strlen(*str + 2)) < info->prec)
// 		*str = pre_join(*str, info->prec - len, rem, 2);
// 	free(rem);
// }

// char		*ft_prec_dig(char *str, t_info *info)
// {
// 	char	*tmp;
// 	char	*rem;
// 	int		len;

// 	rem = NULL;
// 	tmp = NULL;
// 	if (info->sign || info->space || str[0] == '-')
// 	{
// 		rem = ft_strnew(1);
// 		rem[0] = str[0];
// 		if ((len = ft_strlen(str + 1)) < info->prec)
// 			str = pre_join(str, info->prec - len, rem, 1);
// 		free(rem);
// 	}
// 	else if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
// 		prec_dig_help(&str, info, rem);
// 	else if (info->prec > (len = ft_strlen(str)))
// 		str = pre_join(str, info->prec - len, "", 0);
// 	return (str);
// }

// char		*ft_mod_prec(char *str, t_info *info)
// {
// 	char *tmp;

// 	if (info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i' ||
// 		info->bukva == 'o' || info->bukva == 'O' || info->bukva == 'u' ||
// 		info->bukva == 'U' || info->bukva == 'x' || info->bukva == 'X' ||
// 		info->bukva == 'p')
// 		str = ft_prec_dig(str, info);
// 	else if (info->bukva == 's' || info->bukva == 'S')
// 	{
// 		if ((int)ft_strlen(str) > info->prec)
// 		{
// 			tmp = str;
// 			str = ft_strsub(str, 0, info->prec);
// 			free(tmp);
// 		}
// 	}
// 	return (str);
// }

// void	ft_width_help(char **str, t_info *info, int len)
// {
// 	char	*tmp;
// 	char	*buf;

// 	tmp = ft_strnew(info->width - len);
// 	ft_memset(tmp, ' ', info->width - len);
// 	buf = *str;
// 	if (info->minus > 0)
// 		*str = ft_strjoin(*str, tmp);
// 	else
// 		*str = ft_strjoin(tmp, *str);
// 	free(tmp);
// 	free(buf);
// }

// char	*ft_width(char *str, t_info *info)
// {
// 	int		len;
// 	int		tm;

// 	if ((len = ft_strlen(str)) < info->width)
// 	{
// 		if (info->prec < 0 && info->minus != 1 && info->zero == 1)
// 		{
// 			if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
// 				info->width -= 1;
// 			if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
// 				info->width -= 2;
// 			tm = info->prec;
// 			info->prec = info->width;
// 			str = ft_mod_prec(str, info);
// 			info->prec = tm;
// 			return (str);
// 		}
// 		else
// 			ft_width_help(&str, info, len);
// 	}
// 	return (str);
// }


// void		ft_mod(char *str, t_info *info, int un)
// {
// 	if (info->prec == 0 && info->bukva != 'p' && (str[0] == '0' || !str))
// 	{
// 		if (str)
// 			free(str);
// 		str = ft_strnew(0);
// 	}
// 	if (un && info->resh && str[0] != '0')
// 		str = ft_mod_resh(str, info);
// 	else if (un == 0 && str[0])
// 		str = ft_mod_sign(str, info);
// 	if (info->prec > 0)
// 		str = ft_mod_prec(str, info);
// 	if (info->width > 0)
// 		str = ft_width(str, info);
// 	info->res += write(1, str, ft_strlen(str));
// 	free(str);
// }

// void	cast_int(t_info *info)
// {
// 	intmax_t ret;

// 	if (info->size == 3 || info->bukva == 'D')
// 		ret = va_arg(info->list, long);
// 	else if (info->size == 6)
// 		ret = va_arg(info->list, size_t);
// 	else if (info->size == 5)
// 		ret = va_arg(info->list, intmax_t);
// 	else if (info->size == 4)
// 		ret = va_arg(info->list, long long);
// 	else if (info->size == 2)
// 		ret = (short)va_arg(info->list, int);
// 	else if (info->size == 1)
// 		ret = (signed char)va_arg(info->list, int);
// 	else
// 		ret = va_arg(info->list, int);
// 	ft_mod(ft_itoaint(ret), info, 0);
// }

// size_t		ft_len_num(unsigned long long value, int base)
// {
// 	int	count;

// 	count = 0;
// 	if (value <= 0)
// 		count++;
// 	while (value != 0)
// 	{
// 		count++;
// 		value /= base;
// 	}
// 	return (count);
// }

// char		*ft_lower_case(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// 	return (str);
// }

// char		*ft_itoa_base(unsigned long long value, int base, int flag)
// {
// 	char	*itoa;
// 	char	*box;
// 	size_t	len;

// 	box = "0123456789ABCDEF";
// 	len = ft_len_num(value, base);
// 	itoa = ft_strnew(len);
// 	if (itoa)
// 	{
// 		itoa[len] = '\0';
// 		if (value == 0)
// 			itoa[0] = '0';
// 		while (value != 0)
// 		{
// 			itoa[--len] = box[(value % base)];
// 			value = value / base;
// 		}
// 		if (flag == 0)
// 			itoa = ft_lower_case(itoa);
// 	}
// 	return (itoa);
// }

// void	cast_unsigned(t_info *info)
// {
// 	uintmax_t ret;

// 	if (info->size == 3 || info->bukva == 'U' || info->bukva == 'O')
// 		ret = va_arg(info->list, unsigned long);
// 	else if (info->size == 6)
// 		ret = va_arg(info->list, size_t);
// 	else if (info->size == 5)
// 		ret = va_arg(info->list, uintmax_t);
// 	else if (info->size == 4)
// 		ret = va_arg(info->list, unsigned long long);
// 	else if (info->size == 2)
// 		ret = (unsigned short)va_arg(info->list, unsigned int);
// 	else if (info->size == 1)
// 		ret = (unsigned char)va_arg(info->list, unsigned int);
// 	else
// 		ret = va_arg(info->list, unsigned int);
// 	if (info->bukva == 'u' || info->bukva == 'U')
// 		ft_mod(ft_itoa_base(ret, 10, 0), info, 1);
// 	else if (info->bukva == 'o' || info->bukva == 'O')
// 		ft_mod(ft_itoa_base(ret, 8, 0), info, 1);
// 	else
// 		ft_mod(ft_itoa_base(ret, 16, info->bukva == 'X' ? 1 : 0), info, 1);
// }

// int				ft_take_wlen(const uint32_t symbol)
// {
// 	int			size;

// 	size = 0;
// 	if (symbol <= BIT7)
// 		size += 1;
// 	else if (symbol <= BIT11)
// 		size += 2;
// 	else if (symbol <= BIT16)
// 		size += 3;
// 	else if (symbol <= BIT21)
// 		size += 4;
// 	return (size);
// }

// char			*ft_parse_wchar(const uint32_t symbol, int p)
// {
// 	char		*rt;

// 	rt = ft_strnew(4);
// 	if (symbol <= BIT7 && p >= 1)
// 		rt[0] = symbol;
// 	else if (symbol <= BIT11 && p >= 2)
// 	{
// 		rt[0] = ((symbol & 1984) >> 6) | 192;
// 		rt[1] = (symbol & 63) | 128;
// 	}
// 	else if (symbol <= BIT16 && p >= 3)
// 	{
// 		rt[0] = ((symbol & 61440) >> 12) | 224;
// 		rt[1] = ((symbol & 4032) >> 6) | 128;
// 		rt[2] = (symbol & 63) | 128;
// 	}
// 	else if (symbol <= BIT21 && p >= 4)
// 	{
// 		rt[0] = ((symbol & 1835008) >> 18) | 240;
// 		rt[1] = ((symbol & 258048) >> 12) | 128;
// 		rt[2] = ((symbol & 4032) >> 6) | 128;
// 		rt[3] = (symbol & 63) | 128;
// 	}
// 	return (rt);
// }

// void		ft_wputstr(char **d, t_info *info)
// {
// 	int		a;
// 	int		j;

// 	a = 0;
// 	while (d[a])
// 	{
// 		j = 0;
// 		while (d[a][j])
// 		{
// 			info->res += write(1, &d[a][j], 1);
// 			j++;
// 		}
// 		a++;
// 	}
// }

// int			ft_check_len_wch(char **data)
// {
// 	int		i;
// 	int		tmp;

// 	i = 0;
// 	tmp = 0;
// 	while (data[i])
// 	{
// 		tmp += ft_strlen(data[i]);
// 		i++;
// 	}
// 	return (tmp);
// }

// void		ft_place_char(int size, char c, t_info *info)
// {
// 	int		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		info->res += write(1, &c, 1);
// 		i++;
// 	}
// }

// void			ft_make_width(char **data, t_info *info)
// {
// 	int i;

// 	i = 0;
// 	if (info->minus == 1)
// 	{
// 		ft_wputstr(data, info);
// 		ft_place_char(info->width - ft_check_len_wch(data), ' ', info);
// 	}
// 	else if (info->zero == 1)
// 	{
// 		ft_place_char(info->width - ft_check_len_wch(data), '0', info);
// 		ft_wputstr(data, info);
// 	}
// 	else
// 	{
// 		ft_place_char(info->width - ft_check_len_wch(data), ' ', info);
// 		ft_wputstr(data, info);
// 	}
// 	while (data[i])
// 		free(data[i++]);
// 	free(data);
// }

// void			ft_widestr(wchar_t *d, t_info *info)
// {
// 	int			i;
// 	int			p;
// 	char		**s;

// 	i = 0;
// 	while (d[i])
// 		i++;
// 	s = (char**)malloc(sizeof(char*) * (i + 1));
// 	s[i] = NULL;
// 	i = 0;
// 	p = info->prec;
// 	while (d[i])
// 	{
// 		if (info->prec < 0)
// 			p = 4;
// 		s[i] = ft_parse_wchar(d[i], p);
// 		p -= ft_take_wlen(d[i]);
// 		i++;
// 	}
// 	ft_make_width(s, info);
// }

// void		ft_modchar_help(char *str, t_info *info, char *tmp, int len)
// {
// 	tmp = ft_strnew(info->width - len);
// 	if (info->zero > 0 && info->space <= 0)
// 		ft_memset(tmp, '0', info->width - len);
// 	else
// 		ft_memset(tmp, ' ', info->width - len);
// 	if (info->minus > 0)
// 	{
// 		info->res += write(1, str, len);
// 		info->res += write(1, tmp, info->width - len);
// 	}
// 	else
// 	{
// 		info->res += write(1, tmp, info->width - len);
// 		info->res += write(1, str, len);
// 	}
// 	free(tmp);
// }

// void		ft_modchar(char *str, t_info *info)
// {
// 	char	*tmp;
// 	int		len;

// 	if (info->prec != -1 && info->prec < (int)ft_strlen(str))
// 	{
// 		tmp = str;
// 		str = ft_strsub(str, 0, info->prec);
// 		free(tmp);
// 	}
// 	len = ft_strlen(str);
// 	if (info->width > len)
// 		ft_modchar_help(str, info, tmp, len);
// 	else
// 		info->res += write(1, str, len);
// 	free(str);
// }

// void		ft_char(t_info *info)
// {
// 	int			c;
// 	char		ch;

// 	ch = ' ';
// 	c = va_arg(info->list, int);
// 	if (info->width > 0)
// 	{
// 		if (info->zero == 1)
// 			ch = '0';
// 		if (info->minus == 1)
// 		{
// 			info->res += write(1, &c, 1);
// 			ft_place_char(info->width - 1, ch, info);
// 		}
// 		else
// 		{
// 			ft_place_char(info->width - 1, ch, info);
// 			info->res += write(1, &c, 1);
// 		}
// 	}
// 	else
// 		info->res += write(1, &c, 1);
// }

// void	cast_char(t_info *info)
// {
// 	char	*str;
// 	wchar_t *wstr;

// 	if (info->bukva == 'S' || (info->bukva == 's' && info->size == 3))
// 	{
// 		if (!(wstr = va_arg(info->list, wchar_t*)))
// 			ft_widestr(L"(null)", info);
// 		else
// 			ft_widestr(wstr, info);
// 	}
// 	else
// 	{
// 		str = NULL;
// 		if (info->bukva == 's')
// 		{
// 			str = va_arg(info->list, char*);
// 			if (!str)
// 				str = ft_strdup("(null)");
// 			else
// 				str = ft_strdup(str);
// 			ft_modchar(str, info);
// 		}
// 		else if (info->bukva == 'c' || info->bukva == 'C')
// 			ft_char(info);
// 	}
// }

// void	cast_pointer(t_info *info)
// {
// 	uintmax_t	ret;
// 	char		*str;
// 	char		*tmp;
// 	char		*buf;

// 	str = ft_strnew(2);
// 	str[0] = '0';
// 	str[1] = 'x';
// 	ret = (uintmax_t)va_arg(info->list, void*);
// 	if (ret == 0 && info->prec != -1)
// 		buf = str;
// 	else
// 	{
// 		tmp = ft_itoa_base(ret, 16, 0);
// 		buf = ft_strjoin(str, tmp);
// 		free(tmp);
// 		free(str);
// 	}
// 	ft_mod(buf, info, 1);
// }

// void	ft_cast(t_info *info)
// {
// 	if (info->bukva == 's' || info->bukva == 'S' ||
// 		info->bukva == 'c' || info->bukva == 'C')
// 		cast_char(info);
// 	else if (info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i')
// 		cast_int(info);
// 	else if (info->bukva == 'o' || info->bukva == 'O' || info->bukva == 'u'
// 		|| info->bukva == 'U' || info->bukva == 'x' || info->bukva == 'X')
// 		cast_unsigned(info);
// 	else if (info->bukva == 'p')
// 		cast_pointer(info);
// }

// void		write_width(t_info *info)
// {
// 	char	*str;

// 	if (info->bukva == '\0')
// 		return ;
// 	else if (info->width <= 0)
// 		info->res += write(1, &info->bukva, 1);
// 	else
// 	{
// 		str = ft_strnew(info->width);
// 		if (info->zero > 0)
// 			ft_memset(str, '0', info->width);
// 		else
// 			ft_memset(str, ' ', info->width);
// 		if (info->minus > 0)
// 			str[0] = info->bukva;
// 		else
// 			str[info->width - 1] = info->bukva;
// 		info->res += write(1, str, info->width);
// 		free(str);
// 	}
// }

// void	parse_next(t_info *info)
// {
// 	if (info->bukva == 's' || info->bukva == 'S' || info->bukva == 'o'
// 		|| info->bukva == 'O' || info->bukva == 'u' || info->bukva == 'U'
// 		|| info->bukva == 'd' || info->bukva == 'D' || info->bukva == 'i'
// 		|| info->bukva == 'x' || info->bukva == 'X' || info->bukva == 'c'
// 		|| info->bukva == 'C' || info->bukva == 'p')
// 		ft_cast(info);
// 	else
// 		write_width(info);
// }

// int		sort_param(const char *str, t_info *info, int i)
// {
// 	int	tmp;

// 	while (1)
// 	{
// 		tmp = i;
// 		i = manage_signs(str, i, info);
// 		i = manage_width(str, i, info);
// 		i = manage_letters(str, i, info);
// 		if (tmp == i)
// 			break ;
// 	}
// 	info->bukva = str[i];
// 	parse_next(info);
// 	if (!str[i])
// 		return (i);
// 	return (i + 1);
// }

union my_num
{
	intmax_t	imaxt;
	wint_t		wit;
    char c;
    short i;
    long l;
    float f;
    double d;
    char* s;
};

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

void	ft_putustrl(wint_t const *s, int len)
{
	if (!s)
		return (ft_putstr("(null)"));
	while (*s < len)
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

char	*ft_strcut(char *str, int len)
{
	int i;

	i = ft_strlen(str);
	while (i >= len)
		str[i--] = '\0';
	return (str);
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
		else if (someth_else(str[i]))
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

int		deal_with_types(t_info *info, const char *str, int i)
{
	union my_num num;

	if (str[i] == 'd' || str[i] == 'D' || str[i] == 'i')
	{
		intmax_t temp;

		temp = ft_cast_int(temp, info, str, i);
		int prec = info->precision;
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (info->width > 0)
			info->width -= ft_intlen(temp);
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_intlen(temp);
			temp < 0 ? info->precision++ : 0;
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if ((temp >= 0 && info->plus)
			|| (temp >= 0 && info->space && info->zero && info->width > 0))
			info->width--;
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if ((temp >= 0 && info->space && !info->width)
			|| (temp >= 0 && info->space && info->zero && info->width > 0))
		{
			write(1, " ", 1);
			info->res++;

		}
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (temp >= 0 && info->plus)
		{
			write(1, "+", 1);
			info->res++;
		}
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (temp < 0)
			{
				write(1, "-", 1);
				temp *= -1;
				info->res++;
			}
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (temp < 0 && temp != -9223372036854775808U)
		{
			write(1, "-", 1);
			temp *= -1;
			info->res++;
		}
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot)
			return (i);
		char *str = ft_itoa(temp);
		ft_putstr(str);
		info->res += ft_intlen(temp);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 'u' || str[i] == 'U')
	{
		uintmax_t temp;

		temp = ft_cast_hex(temp, info, str, i);
		int prec = info->precision;
		if (info->width > 0)
			info->width -= ft_intlen_u(temp);
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_intlen_u(temp);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (!info->minus && info->zero && info->precision <= 0)
		{
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot)
			return (i);
		char *str = ft_itoa_u(temp);
		ft_putstr(str);
		info->res += ft_intlen_u(temp);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 'o')
	{
		uintmax_t temp;

		temp = ft_cast_hex(temp, info, str, i);
		char* str = ft_itoa_base(temp, 8, 0);
		int prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(str);
		if (info->hash && temp != 0)
		{
			info->width -= 1;
			info->res += 1;
		}
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(str);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (info->hash && temp != 0)
				ft_putstr("0");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot && !info->hash)
			return (i);
		if ((info->hash && temp != 0 && !info->zero)
			|| (info->hash && temp != 0 && info->minus))
		{
			char *tmp = str;
			str = ft_strjoin("0", tmp);
			info->res -= 1;
			free(tmp);
		}
		ft_putstr(str);
		info->res += ft_strlen(str);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 'O')
	{
		uintmax_t temp;
		temp = ft_cast_hex(temp, info, str, i);
		char* str = ft_itoa_base(temp, 8, 1);
		int prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(str);
		if (info->hash && temp != 0)
		{
			info->width -= 1;
			info->res += 1;
		}
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(str);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (info->hash && temp != 0)
				ft_putstr("0");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot && !info->hash)
			return (i);
		if ((info->hash && temp != 0 && !info->zero)
			|| (info->hash && temp != 0 && info->minus))
		{
			char *tmp = str;
			str = ft_strjoin("0", tmp);
			info->res -= 1;
			free(tmp);
		}
		ft_putstr(str);
		info->res += ft_strlen(str);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == 'x')
	{
		uintmax_t temp;

		temp = ft_cast_hex(temp, info, str, i);
		char *str = ft_itoa_base(temp, 16, 0);
		int prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(str);
		if (info->hash && temp != 0)
		{
			info->width -= 2;
			info->res += 2;
		}
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(str);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (info->hash && temp != 0)
				ft_putstr("0x");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot)
			return (i);
		if ((info->hash && temp != 0 && !info->zero)
			|| (info->hash && temp != 0 && info->minus))
		{
			char *tmp = str;
			str = ft_strjoin("0x", tmp);
			info->res -= 2;
			free(tmp);
		}
		ft_putstr(str);
		info->res += ft_strlen(str);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 'X')
	{
		uintmax_t temp;

		temp = ft_cast_hex(temp, info, str, i);
		char* str = ft_itoa_base(temp, 16, 1);
		int prec = info->precision;
		if (info->width > 0)
			info->width -= ft_strlen(str);
		if (info->hash && temp != 0)
		{
			info->width -= 2;
			info->res += 2;
		}
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_strlen(str);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (!info->minus && info->zero && info->precision <= 0)
		{
			if (info->hash && temp != 0)
				ft_putstr("0X");
			while (info->width-- > 0)
				write(1, "0", 1);
		}
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		while (info->precision-- > 0)
			write(1, "0", 1);
		if (temp == 0 && prec == 0 && info->dot)
			return (i);
		if ((info->hash && temp != 0 && !info->zero)
			|| (info->hash && temp != 0 && info->minus))
		{
			char *tmp = str;
			str = ft_strjoin("0X", tmp);
			info->res -= 2;
			free(tmp);
		}
		ft_putstr(str);
		info->res += ft_strlen(str);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 'p')
	{
		uintmax_t	temp;

		temp = va_arg(info->va_list, uintmax_t);
		int prec = info->precision;
		char *str = ft_itoa_base(temp, 16, 0);
		if (info->width > 0)
			info->width -= ft_strlen(str) + 2;
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			temp != 0 ? info->precision -= ft_strlen(str) : 0;
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (temp == 0 && info->dot)
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
		ft_putstr(str);
		info->res += ft_strlen(str) + 2;
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
		free(str);
	}
	else if (str[i] == 's')
	{
		char *temp;

		temp = va_arg(info->va_list, char*);
		int prec = info->precision;
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (!temp)
			temp = "(null)";
		// printf("1 info->width %d\n", info->width);
		// printf("1 info->precision %d\n", info->precision);
		if (info->width > 0 && ft_strlen(temp) > info->precision)
		{
			if (info->precision > 0)
			{
				printf("1\n");
				info->width -= info->precision;
			}
			else if (info->precision > 0 && !info->dot)
			{
				info->width -= ft_strlen(temp);
			}
		}
		// printf("2 info->width %d\n", info->width);
		// printf("2 info->precision %d\n", info->precision);
		if (info->precision > 0 && ft_strlen(temp) < info->precision)
			info->width -= ft_strlen(temp);
		// printf("3 info->width %d\n", info->width);
		// printf("3 info->precision %d\n", info->precision);
		// printf("13 info->res %d\n", info->res);
		if (info->width > 0)
			info->res += info->width;
		// printf("2 info->res %d\n", info->res);
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		// printf("4 info->width %d\n", info->width);
		// printf("4 info->precision %d\n", info->precision);
		if (!info->minus && info->zero && info->precision <= 0)
			while (info->width-- > 0)
				write(1, "0", 1);
		else if (!info->minus && info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);

		if (info->precision > 0 && ft_strlen(temp) > info->precision)
		{
			ft_putstrl(temp, info->precision);
			info->res += info->precision;
			// printf("3 info->res %d\n", info->res);
		}
		else
		{
			ft_putstrl(temp, info->width);
			info->res += info->width + 1;
			// printf("4 info->res %d\n", info->res);
		}
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == 'S')
	{
		wint_t *temp;

		temp = va_arg(info->va_list, wint_t*);
		int prec = info->precision;
		// printf("info->width %d\n", info->width);
		// printf("info->precision %d\n", info->precision);
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (!temp)
			temp = L"(null)";
		info->width -= ft_ustrlen(temp);
		if (info->width && temp == 0 && prec == 0 && info->dot)
			info->width++;
		if (info->precision > 0)
		{
			info->precision -= ft_ustrlen(temp);
			info->width = info->precision > 0 ?
				info->width - info->precision : info->width;
		}
		// printf("info->width %d\n", info->width);
		// printf("info->precision %d\n", info->precision);
		if (info->width > 0)
			info->res += info->width;
		if (info->precision > 0)
			info->res += info->precision;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		if (temp == 0 && prec == 0 && info->dot)
			return (i);
		ft_putustrl(temp, info->precision);
		info->res += ft_ustrlen(temp);
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == 'c' || str[i] == 'C')
	{
		wint_t temp;

		if (info->cast == _LONG || str[i] == 'C')
			temp = va_arg(info->va_list, wchar_t);
		else
			temp = (unsigned char)va_arg(info->va_list, unsigned int);
		if (info->star && info->width < 0)
		{
			info->minus = 1;
			info->width = -info->width;
		}
		if (info->width > 0)
			info->width -= 1;
		if (info->width > 0)
			info->res += info->width;
		int wid = info->width;
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
			ft_putchar(temp);
			info->res += ft_ucharlen(temp);
		}
		else
		{
			write(1, &temp, 1);
			info->res++;
		}
		if (info->minus)
			while (wid-- > 0)
				write(1, " ", 1);
	}
	else if (str[i] == '%' && !info->smt)
	{
		if (info->width > 0)
			info->width -= 1;
		if (info->plus)
			info->width--;
		if (info->width > 0)
			info->res += info->width;
		int wid = info->width;
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
			while (wid-- > 0)
				write(1, " ", 1);
	}
	else if (info->smt)
	{
		if (info->width > 0)
			info->width -= 1;
		if (info->plus)
			info->width--;
		if (info->width > 0)
			info->res += info->width;
		int wid = info->width;
		if (!info->minus && !info->zero)
			while (info->width-- > 0)
				write(1, " ", 1);
		write(1, &str[i], 1);
		info->res += 1;
		if (info->minus)
			while (wid-- > 0)
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

// int main()
// {
// 	// setlocale( LC_ALL, "" );
// 	int i = 1111;
// 	int j = 1;
// 	int res = 0;
// 	char *str = "lala";
// 	char *pointer;
// 	// res = ft_printf("%d kaka\n", i);
// 	// printf("%d\n", res);
// 	// res = ft_printf("%s lala\n", str);
// 	// printf("%d\n", res); 					//// cheking string and int

// //						//// cheking int

// 	// printf("ret1: %d\n",    printf("or: %10.5d\n", -650));
// 	// printf("ret2: %d\n", ft_printf("my: %10.5d\n", -650));


// 	   printf("or:|% 0-+10.d\n", 1111);
// 	ft_printf("my:|% 0-+10.d\n", 1111);

	// mr = ft_printf("MINE>\t[%+05d]\n", -650);
	// or = printf("ORIG>\t[%+05d]\n", -650);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-05d]\n", -650);
	// or = printf("ORIG>\t[%-05d]\n", -650);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+-05d]\n", -650);
	// or = printf("ORIG>\t[%+-05d]\n", -650);

	// mr = ft_printf("MINE>\t[% 5d]\n", -650);
	// or = printf("ORIG>\t[% 5d]\n", -650);

	// mr = ft_printf("MINE>\t[%'d]\n", 65000);
	// or = printf("ORIG>\t[%'d]\n", 65000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%'d]\n", 6500000);
	// or = printf("ORIG>\t[%'d]\n", 6500000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+'d]\n", 65000);
	// or = printf("ORIG>\t[%+'d]\n", 65000);


	//    printf("OR: |%*.*d\n", 2, 7, i); //
	// ft_printf("MY: |%*.*d\n", 2, 7, i);
	// j++;
	//    printf("%d OR: %020.10d\n", j, 0); //
	// ft_printf("%d MY: %020.10d\n", j, 0);
	// j++;
	//    printf("%d OR: %10.5d\n", j, i); // width
	// ft_printf("%d MY: %10.5d\n", j, i);
	// j++;
	//    printf("%d OR: %5d\n", j, i);
	// ft_printf("%d MY: %5d\n", j, i);
	// j++;
	//    printf("%d OR: %5d\n", j, 0);
	// ft_printf("%d MY: %5d\n", j, 0);
	// j++;
	//    printf("%d OR: %.20d\n", j, i); // precision
	// ft_printf("%d MY: %.20d\n", j, i);
	// j++;
	//    printf("%d OR: %.5d\n", j, i);
	// ft_printf("%d MY: %.5d\n", j, i);
	// j++;
	//    printf("%d OR: %.5d\n", j, 0);
	// ft_printf("%d MY: %.5d\n", j, 0);
	// j++;
	//    printf("%d OR: %#d\n", j, i); // hash
	// ft_printf("%d MY: %#d\n", j, i);
	// j++;
	//    printf("%d OR: %#5d\n", j, 0);
	// ft_printf("%d MY: %#5d\n", j, 0);
	// j++;

	//    printf("%d OR: %#20d\n", j, i); // hash + width
	// ft_printf("%d MY: %#20d\n", j, i);
	// j++;
	//    printf("%d OR: %#5d\n", j, i);
	// ft_printf("%d MY: %#5d\n", j, i);
	// j++;
	//    printf("%d OR: %#5d\n", j, 0);
	// ft_printf("%d MY: %#5d\n", j, 0);
	// j++;
	//    printf("%d OR: %#.20d\n", j, i); // hash + precision
	// ft_printf("%d MY: %#.20d\n", j, i);
	// j++;
	//    printf("%d OR: %#.5d\n", j, i);
	// ft_printf("%d MY: %#.5d\n", j, i);
	// j++;
	//    printf("%d OR: %#.5d\n", j, 0);
	// ft_printf("%d MY: %#.5d\n", j, 0);
	// j++;

	//    printf("%d OR: %#20d\n", j, 0);
	// ft_printf("%d MY: %#20d\n", j, 0);
	// j++;
	//    printf("%d OR: %#5d\n", j, 0);
	// ft_printf("%d MY: %#5d\n", j, 0);
	// j++;
	//    printf("%d OR: %#.20d\n", j, 0);
	// ft_printf("%d MY: %#.20d\n", j, 0);
	// j++;
	//    printf("%d OR: %.5d\n", j, 0);
	// ft_printf("%d MY: %.5d\n", j, 0);
	// j++;
	//    printf("%d OR: %-20d\n", j, 0);
	// ft_printf("%d MY: %-20d\n", j, 0);
	// j++;
	//    printf("%d OR: %#-5d\n", j, 0);
	// ft_printf("%d MY: %#-5d\n", j, 0);
	// j++;

	//    printf("%d OR: %#015d\n", j, i);
	// ft_printf("%d MY: %#015d\n", j, i);
	// j++;
	//    printf("%d OR: %#05d\n", j, i);
	// ft_printf("%d MY: %#05d\n", j, i);
	// j++;
	//    printf("%d OR: %#020d\n", j, 0);
	// ft_printf("%d MY: %#020d\n", j, 0);
	// j++;
	//    printf("%d OR: %#05d\n", j, 0);
	// ft_printf("%d MY: %#05d\n", j, 0);
	// j++;
	//    printf("%d OR: %20.10d\n", j, i);
	// ft_printf("%d MY: %20.10d\n", j, i);
	// j++;
	//    printf("%d OR: %10.10d\n", j, i);
	// ft_printf("%d MY: %10.10d\n", j, i);
	// j++;
	//    printf("%d OR: %5.10d\n", j, i);
	// ft_printf("%d MY: %5.10d\n", j, i);
	// j++;
	//    printf("%d OR: %#-20.10d\n", j, i);
	// ft_printf("%d MY: %#-20.10d\n", j, i);
	// j++;
	//    printf("%d OR: %#-5.10d\n", j, i);
	// ft_printf("%d MY: %#-5.10d\n", j, i);
	// j++;
	//    printf("%d OR: %#-20.10d\n", j, 0);
	// ft_printf("%d MY: %#-20.10d\n", j, 0);
	// j++;
	//    printf("%d OR: %#-5.10d\n", j, 0);
	// ft_printf("%d MY: %#-5.10d\n", j, 0);
	// j++;
	//    printf("%d OR: %#020.10d\n", j, i); //
	// ft_printf("%d MY: %#020.10d\n", j, i);
	// j++;
	//    printf("%d OR: %#05.10d\n", j, i);
	// ft_printf("%d MY: %#05.10d\n", j, i);
	// j++;
	//    printf("%d OR: %#020.10d\n", j, 0); //
	// ft_printf("%d MY: %#020.10d\n", j, 0);
	// j++;
	//    printf("%d OR: %#05.10d\n", j, 0);
	// ft_printf("%d MY: %#05.10d\n", j, 0);
	// j++;
	//    printf("%d OR: %#010.10d\n", j, i);
	// ft_printf("%d MY: %#010.10d\n", j, i);
	// j++;

//

// 	return (0);
// }

// void	ft_print_result(int mr, int or, int line)
// {
// 	static int c = 0;
// 	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
// 	if (mr == or)
// 		printf("\t\033[32m✔\033[0m");
// 	else
// 		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
// 			   line - 3, line);
// 	printf("\n---------------\n");
// 	c++;
// }



// int	mais(void)
// {
// 	int	or, mr;
// 	char	**test;

// 	test = malloc(sizeof(char*));
// 	or = 0;
// 	mr = 0;
// 	printf("\033[1;37m======== %%d ========\033[0m\n");

// 	mr = ft_printf("MINE>\t[%d]\n", 650);
// 	or = printf("ORIG>\t[%d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%d]\n", -650);
// 	or = printf("ORIG>\t[%d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+d]\n", 650);
// 	or = printf("ORIG>\t[%+d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+1d]\n", 650);
// 	or = printf("ORIG>\t[%+1d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+10d]\n", 650);
// 	or = printf("ORIG>\t[%+10d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+10d]\n", -650);
// 	or = printf("ORIG>\t[%+10d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%10d]\n", 650);
// 	or = printf("ORIG>\t[%10d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%-10d]\n", 650);
// 	or = printf("ORIG>\t[%-10d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%-5d]\n", 650);
// 	or = printf("ORIG>\t[%-5d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[% d]\n", 650);
// 	or = printf("ORIG>\t[% d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[% 5d]\n", 650);
// 	or = printf("ORIG>\t[% 5d]\n", 650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[% d]\n", -650);
// 	or = printf("ORIG>\t[% d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[% 5d]\n", -650);
// 	or = printf("ORIG>\t[% 5d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%05d]\n", -650);
// 	or = printf("ORIG>\t[%05d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+05d]\n", -650);
// 	or = printf("ORIG>\t[%+05d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%-05d]\n", -650);
// 	or = printf("ORIG>\t[%-05d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+-05d]\n", -650);
// 	or = printf("ORIG>\t[%+-05d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+-09d]\n", -650);
// 	or = printf("ORIG>\t[%+-09d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+09d]\n", -650);
// 	or = printf("ORIG>\t[%+09d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+-1d]\n", -650);
// 	or = printf("ORIG>\t[%+-1d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+01d]\n", -650);
// 	or = printf("ORIG>\t[%+01d]\n", -650);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%'d]\n", 65000);
// 	or = printf("ORIG>\t[%'d]\n", 65000);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%'d]\n", 6500000);
// 	or = printf("ORIG>\t[%'d]\n", 6500000);
// 	ft_print_result(mr, or, __LINE__);

// 	mr = ft_printf("MINE>\t[%+'d]\n", 65000);
// 	or = printf("ORIG>\t[%+'d]\n", 65000);
// 	ft_print_result(mr, or, __LINE__);

// 	printf("\033[1;37m======== end %%d =====\033[0m\n\n");

	// printf("\033[1;37m======== %%u ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%u]\n", 650);
	// or = printf("ORIG>\t[%u]\n", 650);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%u]\n", 4000000000);
	// or = printf("ORIG>\t[%u]\n", 4000000000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%u]\n", -650);
	// or = printf("ORIG>\t[%u]\n", -650);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>[\t%+-10u]\n", 12345);
	// or = printf(   "ORIG>[\t%+-10u]\n", 12345);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>[\t%+10u]\n", 12345);
	// or = printf(   "ORIG>[\t%+10u]\n", 12345);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m======== end %%u =====\033[0m\n\n");


	// printf("\033[1;37m======== %%s ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%s]\n", "");
	// or = printf("ORIG>\t[%s]\n", "");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%10s]\n", "");
	// or = printf("ORIG>\t[%10s]\n", "");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%s]\n", NULL);
	// or = printf("ORIG>\t[%s]\n", NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%s]\n", "Coconut");
	// or = printf("ORIG>\t[%s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% s]\n", "Coconut");
	// or = printf("ORIG>\t[% s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% 2s]\n", "Coconut");
	// or = printf("ORIG>\t[% 2s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-4s]\n", "Coconut");
	// or = printf("ORIG>\t[%-4s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+8s]\n", "Coconut");
	// or = printf("ORIG>\t[%+8s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+15s]\n", "Coconut");
	// or = printf("ORIG>\t[%+15s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-15s]\n", "Coconut");
	// or = printf("ORIG>\t[%-15s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%15s]\n", "Coconut");
	// or = printf("ORIG>\t[%15s]\n", "Coconut");
	// ft_print_result(mr, or, __LINE__);


	// printf("\033[1;37m======== end %%s =====\033[0m\n\n");


	// printf("\033[1;37m======== %%c ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%c]\n", '"');
	// or = printf("ORIG>\t[%c]\n", '"');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+10c]\n", 'r');
	// or = printf("ORIG>\t[%+10c]\n", 'r');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-10c]\n", 'r');
	// or = printf("ORIG>\t[%-10c]\n", 'r');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%010c]\n", 'r');
	// or = printf("ORIG>\t[%010c]\n", 'r');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+-10c]\n", 'r');
	// or = printf("ORIG>\t[%+-10c]\n", 'r');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%0+10c]\n", 'r');
	// or = printf("ORIG>\t[%0+10c]\n", 'r');
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m======== end %%c =====\033[0m\n\n");


	// printf("\033[1;37m======== %%o ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%o]\n", 2048);
	// or = printf("ORIG>\t[%o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% o]\n", 777);
	// or = printf("ORIG>\t[% o]\n", 777);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+o]\n", 128);
	// or = printf("ORIG>\t[%+o]\n", 128);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-o]\n", 48);
	// or = printf("ORIG>\t[%-o]\n", 48);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+5o]\n", 10);
	// or = printf("ORIG>\t[%+5o]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5o]\n", 2048);
	// or = printf("ORIG>\t[%-5o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+10o]\n", 2048);
	// or = printf("ORIG>\t[%+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%010o]\n", 2048);
	// or = printf("ORIG>\t[%010o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-+10o]\n", 2048);
	// or = printf("ORIG>\t[%-+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	// or = printf("ORIG>\t[%-0+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#o]\n", 48);
	// or = printf("ORIG>\t[%#o]\n", 48);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+10o]\n", 2048);
	// or = printf("ORIG>\t[%#+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	// or = printf("ORIG>\t[%-0+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-0+10o]\n", 2048);
	// or = printf("ORIG>\t[%-0+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);


	// mr = ft_printf("MINE>\t[%#-0+10o]\n", 2048);
	// or = printf("ORIG>\t[%#-0+10o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-0#+3o]\n", 2048);
	// or = printf("ORIG>\t[%-0#+3o]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%o]\n", 02047);
	// or = printf("ORIG>\t[%o]\n", 02047);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%o]\n", 02047);
	// or = printf("ORIG>\t[%o]\n", 02047);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m======== end %%o =====\033[0m\n\n");

	// printf("\033[1;37m======== %%x and %%X ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%x]\n", 16);
	// or = printf("ORIG>\t[%x]\n", 16);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%x]\n", 2048);
	// or = printf("ORIG>\t[%x]\n", 2048);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%x]\n", 16777215);
	// or = printf("ORIG>\t[%x]\n", 16777215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%X]\n", 6777215);
	// or = printf("ORIG>\t[%X]\n", 6777215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#x]\n", 1677215);
	// or = printf("ORIG>\t[%#x]\n", 1677215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#X]\n", 1677725);
	// or = printf("ORIG>\t[%#X]\n", 1677725);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+x]\n", 1777215);
	// or = printf("ORIG>\t[%#+x]\n", 1777215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#-X]\n", 16215);
	// or = printf("ORIG>\t[%#-X]\n", 16215);
	// ft_print_result(mr, or, __LINE__);

	// printf("\n\033[1;37m=[HARD]= %%x and %%X ========\033[0m\n\n");

	// mr = ft_printf("MINE>\t[%#+9x]\n", 177215);
	// or = printf("ORIG>\t[%#+9x]\n", 177215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#-15X]\n", 167715);
	// or = printf(   "ORIG>\t[%#-15X]\n", 167715);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%# +9x]\n", 17215);
	// or = printf(   "ORIG>\t[%# +9x]\n", 17215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#'-15X]\n", 167715);
	// or = printf(   "ORIG>\t[%#'-15X]\n", 167715);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%020x]\n", 1254789652);
	// or = printf(   "ORIG>\t[%020x]\n", 1254789652);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#020x]\n", 1254789652);
	// or = printf(   "ORIG>\t[%#020x]\n", 1254789652);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+020x]\n", 1254789652);
	// or = printf(   "ORIG>\t[%#+020x]\n", 1254789652);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+20x]\n", 1254789652);
	// or = printf(   "ORIG>\t[%#+20x]\n", 1254789652);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
	// or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+20x]\n", 0xffffff);
	// or = printf(   "ORIG>\t[%#+20x]\n", 0xffffff);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m======== end %%x and %%X ====\033[0m\n\n");

	// printf("\033[1;37m======== %%p ========\033[0m\n");

	// mr = ft_printf("MINE>\t[%p]\n", &mr);
	// or = printf(   "ORIG>\t[%p]\n", &mr);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%p]\n", &or);
	// or = printf(   "ORIG>\t[%p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%10p]\n", &mr);
	// or = printf(   "ORIG>\t[%10p]\n", &mr);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+10p]\n", &or);
	// or = printf(   "ORIG>\t[%+10p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-10p]\n", &mr);
	// or = printf(   "ORIG>\t[%-10p]\n", &mr);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+14p]\n", &or);
	// or = printf(   "ORIG>\t[%+14p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+017p]\n", &or);
	// or = printf(   "ORIG>\t[%+017p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+-017p]\n", &or);
	// or = printf(   "ORIG>\t[%+-017p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+#-017p]\n", &or);
	// or = printf(   "ORIG>\t[%+#-017p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%+-20p]\n", &or);
	// or = printf(   "ORIG>\t[%+-20p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+-020p]\n", &or);
	// or = printf(   "ORIG>\t[%#+-020p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% #+-020p]\n", &or);
	// or = printf(   "ORIG>\t[% #+-020p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#+-020p]\n", &or);
	// or = printf(   "ORIG>\t[% '#+-020p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+020p]\n", &or);
	// or = printf(   "ORIG>\t[%#+020p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#+020p]\n", &or);
	// or = printf(   "ORIG>\t[% '#+020p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#+20p]\n", &or);
	// or = printf(   "ORIG>\t[% '#+20p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#20p]\n", &or);
	// or = printf(   "ORIG>\t[% '#20p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p]\n", &or);
	// or = printf(   "ORIG>\t[% '#p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p]\n", NULL);
	// or = printf(   "ORIG>\t[% '#p]\n", NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p]\n", 140734573365944);
	// or = printf(   "ORIG>\t[% '#p]\n", 140734573365944);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p]\n", (void *)ft_printf);
	// or = printf(   "ORIG>\t[% '#p]\n", (void *)ft_printf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p %p]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[% '#p %p]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#10p %-5p]\n", test, NULL);
	// or = printf(   "ORIG>\t[% '#10p %-5p]\n", test, NULL);
	// ft_print_result(mr, or, __LINE__);

	// free(test);
	// test = 4587;
	// mr = ft_printf("MINE>\t[% '#10p %-5p]\n", test, NULL);
	// or = printf(   "ORIG>\t[% '#10p %-5p]\n", test, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p %p]\n", NULL);
	// or = printf(   "ORIG>\t[% '#p %p]\n", NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#p %p]\n", 0234234, 'b');
	// or = printf(   "ORIG>\t[% '#p %p]\n", 0234234, 'b');
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m==== %%p + modifiers ===\033[0m\n");

	// mr = ft_printf("MINE>\t[%hhp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%hhp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%hp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%hp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%lp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%lp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%llp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%llp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%jp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%jp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%tp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%tp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%zp]\n", (void *)ft_printf, NULL);
	// or = printf(   "ORIG>\t[%zp]\n", (void *)ft_printf, NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%lld]\n", 9223372036854775807);
	// or = printf(   "ORIG>\t[%lld]\n", 9223372036854775807);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%lli]\n", 9223372036854775807);
	// or = printf(   "ORIG>\t[%lli]\n", 9223372036854775807);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%llu]\n", 18446744073709551615);
	// or = printf(   "ORIG>\t[%llu]\n", 18446744073709551615);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m==== %%p + double attr ===\033[0m\n");

	// mr = ft_printf("MINE>\t[%-20+p]\n", &or);
	// or = printf(   "ORIG>\t[%-20+p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-20+lp]\n", &or);
	// or = printf(   "ORIG>\t[%-20+lp]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-20+-p]\n", &or);
	// or = printf(   "ORIG>\t[%-20+-p]\n", &or);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m======== end %%p ====\033[0m\n\n");


	// printf("\033[1;37m==== Width parameter ===\033[0m\n");

	// mr = ft_printf("MINE>\t[%*d]\n", 10, 999);
	// or = printf(   "ORIG>\t[%*d]\n", 10, 999);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%*d]\n", -10, 999);
	// or = printf(   "ORIG>\t[%*d]\n", -10, 999);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%*d]\n", 999);
	// or = printf(   "ORIG>\t[%*d]\n", 999);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%*i]\n", 10, 123);
	// or = printf(   "ORIG>\t[%*i]\n", 10, 123);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%*s]\n", 10, "chamo");
	// or = printf(   "ORIG>\t[%*s]\n", 10, "chamo");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%*c]\n", 8, 'c');
	// or = printf(   "ORIG>\t[%*c]\n", 8, 'c');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-*c]\n", 8, 'k');
	// or = printf(   "ORIG>\t[%-*c]\n", 8, 'k');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[% '#*p]\n", 18, &or);
	// or = printf(   "ORIG>\t[% '#*p]\n", 18, &or);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#'-*X]\n", 18, 167715);
	// or = printf(   "ORIG>\t[%#'-*X]\n", 18, 167715);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#+*x]\n", 25, 1777215);
	// or = printf("ORIG>\t[%#+*x]\n", 25, 1777215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%#-*X]\n", 25, 16215);
	// or = printf("ORIG>\t[%#-*X]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);


	// printf("\033[1;37m== End Width parameter ==\033[0m\n\n");

	// printf("\033[1;37m= End Numbered width parameter =\033[0m\n");

	// mr = ft_printf("MINE>\t[%*2$d]\n", 10, 40);
	// or = printf(   "ORIG>\t[%*2$d]\n", 10, 40);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m== End Width parameter ==\033[0m\n\n");

	// printf("\033[1;37m==== Crashtest zone ===\033[0m\n");

	// mr = ft_printf("MINE>\t[]\n", 25, 16215);
	// or = printf("ORIG>\t[]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%d]\n");
	// or = printf("ORIG>\t[%d]\n");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
	// or = printf(   "ORIG>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%]\n", 25, 16215);
	// or = printf("ORIG>\t[%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%%]\n", 25, 16215);
	// or = printf("ORIG>\t[%%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%%%]\n", 25, 16215);
	// or = printf("ORIG>\t[%%%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[30%%]\n", 25, 16215);
	// or = printf("ORIG>\t[30%%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%30%]\n", 25, 16215);
	// or = printf("ORIG>\t[%30%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%%%%]\n", 25, 16215);
	// or = printf("ORIG>\t[%%%%]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%{after]\n", 25, 16215);
	// or = printf("ORIG>\t[%{after]\n", 25, 16215);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m== End Crashtest zone ==\033[0m\n\n");


	// printf("\033[1;37m==== %%d + modifiers ===\033[0m\n");

	// mr = ft_printf("MINE>\t[%hhd]\n", 123456789);
	// or = printf(   "ORIG>\t[%hhd]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%hd]\n", 123456789);
	// or = printf(   "ORIG>\t[%hd]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%lld]\n", 123456789);
	// or = printf(   "ORIG>\t[%lld]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%ld]\n", 123456789);
	// or = printf(   "ORIG>\t[%ld]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%jd]\n", 123456789);
	// or = printf(   "ORIG>\t[%jd]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%td]\n", 123456789);
	// or = printf(   "ORIG>\t[%td]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%zd]\n", 123456789);
	// or = printf(   "ORIG>\t[%zd]\n", 123456789);
	// ft_print_result(mr, or, __LINE__);

	// printf("\033[1;37m== End %%d + modifiers ==\033[0m\n\n");


	// printf("\033[1;37m==== precision modifiers ===\033[0m\n");


	// mr = ft_printf("MINE>\t[%.4d]\n", 10);
	// or = printf(   "ORIG>\t[%.4d]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-.4d]\n", 10000);
	// or = printf(   "ORIG>\t[%-.4d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%.1d]\n", 10000);
	// or = printf(   "ORIG>\t[%.1d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-.0d]\n", 10000);
	// or = printf(   "ORIG>\t[%-.0d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4d]\n", 10);
	// or = printf(   "ORIG>\t[%5.4d]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-8.4d]\n", 10);
	// or = printf(   "ORIG>\t[%-8.4d]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4d]\n", 10);
	// or = printf(   "ORIG>\t[%-5.4d]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-+8.4d]\n", 10);
	// or = printf(   "ORIG>\t[%-+8.4d]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%2.4d]\n", 10000);
	// or = printf(   "ORIG>\t[%2.4d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%10.1d]\n", 10000);
	// or = printf(   "ORIG>\t[%10.1d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%4.0d]\n", 10000);
	// or = printf(   "ORIG>\t[%4.0d]\n", 10000);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4i]\n", 10);
	// or = printf(   "ORIG>\t[%-5.4i]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%8.4i]\n", 10);
	// or = printf(   "ORIG>\t[%8.4i]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4u]\n", 10);
	// or = printf(   "ORIG>\t[%5.4u]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-8.4u]\n", 10);
	// or = printf(   "ORIG>\t[%-8.4u]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4o]\n", 10);
	// or = printf(   "ORIG>\t[%5.4o]\n", 10);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-8.6o]\n", 0456);
	// or = printf(   "ORIG>\t[%-8.6o]\n", 0456);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%18.12o]\n", 0777777777);
	// or = printf(   "ORIG>\t[%18.12o]\n", 0777777777);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4p]\n", 0xfaf);
	// or = printf(   "ORIG>\t[%5.4p]\n", 0xfaf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%8.4p]\n", NULL);
	// or = printf(   "ORIG>\t[%8.4p]\n", NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4p]\n", 0xfaf);
	// or = printf(   "ORIG>\t[%-5.4p]\n", 0xfaf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-8.4p]\n", NULL);
	// or = printf(   "ORIG>\t[%-8.4p]\n", NULL);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4x]\n", 0xfaf);
	// or = printf(   "ORIG>\t[%5.4x]\n", 0xfaf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4X]\n", 0xfaf);
	// or = printf(   "ORIG>\t[%5.4X]\n", 0xfaf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4X]\n", 0xfaf);
	// or = printf(   "ORIG>\t[%-5.4X]\n", 0xfaf);
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4c]\n", 'k');
	// or = printf(   "ORIG>\t[%5.4c]\n", 'k');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4c]\n", 'k');
	// or = printf(   "ORIG>\t[%-5.4c]\n", 'k');
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%5.4s]\n", "ok");
	// or = printf(   "ORIG>\t[%5.4s]\n", "ok");
	// ft_print_result(mr, or, __LINE__);

	// mr = ft_printf("MINE>\t[%-5.4s]\n", "ok");
	// or = printf(   "ORIG>\t[%-5.4s]\n", "ok");
	// ft_print_result(mr, or, __LINE__);


	// printf("\033[1;37m== End precision modifiers ==\033[0m\n\n");

// 	return (0);
// }
