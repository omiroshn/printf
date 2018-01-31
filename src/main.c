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
	info->sign_char = 0;
	info->minus = 0;
	info->plus = 0;
	info->zero = 0;
	info->resh = 0;
	info->space = 0;
}

int		manage_signs(const char *str, int i, t_info *info)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == '0' || str[i] == '#'
		|| str[i] == ' ')
	{
		if (str[i] == '-' && !(info->zero = 0))
			info->minus = 1;
		else if (str[i] == '+')
			info->plus = 1;
		else if (str[i] == '0' && !info->minus)
			info->zero = 1;
		else if (str[i] == '#')
			info->resh = 1;
		else if (str[i] == ' ' && info->plus != 1)
			info->space = 1;
		i++;
	}
	return (i);
}

int		manage_digits(const char *str, int i, t_info *info, va_list list)
{
	if (str[i] == '.')
	{
		info->prec = 0;
		i++;
		if (str[i] == '*')
		{
			info->prec = va_arg(list, int);
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

int		manage_width(const char *str, int i, t_info *info, va_list list)
{
	if (str[i] == '*')
	{
		info->width = va_arg(list, int);
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
	i = manage_digits(str, i, info, list);
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

int		sort_param(const char *str, va_list list, t_info *info, int i)
{
	int	tmp;

	while (1)
	{
		tmp = i;
		i = manage_signs(str, i, info);        //+
		i = manage_width(str, i, info, list);  //
		i = manage_letters(str, i, info);      //
		if (tmp == i)
			break ;
	}
	info->sign_char = str[i];
	//parse_next(info, args);
	if (!str[i])
		return (i);
	return (0);
}

int		parse_argument(const char *str, va_list list)
{
	int		i;
	t_info	info;
	
	i = 0;
	init(&info);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' && (i += 2))
				info.res += write(1, "%", 1);
			else
				i = sort_param(str, list, &info, ++i);
		}
		else
			info.res += write(1, &str[i++], 1);
	}
	return (info.res);
}

int		ft_printf(const char *format, ...)
{
	int		res;
	va_list	list;

	res = 0;
	va_start(list, format);
	res = parse_argument(format, list);
	va_end(list);
	return (res);
}




int		main(void)
{
	int res1;
	int res2;

	res1 = 0;
	res2 = 0;
	res1 =    printf("%0*x\n", 8, 15);
	res2 = ft_printf("%% 123\n");
	printf("1: %d\n", res1);
	printf("2: %d\n", res2);
}
