/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:26:20 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/30 18:13:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"

#define _LONG 1
#define _UCHAR 2
#define _USHORTINT 3
#define _LONGLONG 4
#define _UINTMAXT 5
#define _SIZET 6

typedef struct		my_num
{
	intmax_t		imaxt;
	intmax_t		uimaxt;
	wint_t			*swit;
	wint_t			cwit;
	int				prec;
	int				wid;
	char			*s;
	char			*s2;
}					s_num;

typedef	struct		s_info
{
	va_list			va_list;
	int				res;
	int				hash;
	int				minus;
	int				plus;
	int				zero;
	int				space;
	int				star;
	int				percent;
	int				width;
	int				precision;
	int				cast;
	int				dot;
	int				smt;
	int				changed;
}					t_info;

int		ft_printf(const char *msg, ...);
uintmax_t	ft_cast_hex(uintmax_t temp, t_info *info, const char *str, int i);
intmax_t	ft_cast_int(intmax_t temp, t_info *info, const char *str, int i);
int		deal_with_flags(t_info *info, const char *str, int i);
int		print_d(t_info *info, s_num n, const char *str, int i);
int		print_u(t_info *info, s_num n, const char *str, int i);
int		print_o(t_info *info, s_num n, const char *str, int i);
int		print_lo(t_info *info, s_num n, const char *str, int i);
int		print_x(t_info *info, s_num n, const char *str, int i);
int		print_lx(t_info *info, s_num n, const char *str, int i);
int		print_p(t_info *info, s_num n, const char *str, int i);
int		print_ls(t_info *info, s_num n, const char *str, int i);
int		print_s(t_info *info, s_num n, const char *str, int i);
int		print_c(t_info *info, s_num n, const char *str, int i);
char	*ft_itoa_u(uintmax_t n);
int		ft_intlen_u(uintmax_t num);
int		ft_intlen(intmax_t num);
void	init_flags(t_info *info);
int		ft_ucharlen(int c);
int		ft_ustrlen(wchar_t *str);
int		ft_putustrl(wint_t *s, int len);
int		ft_spreclen(wint_t *s, int len);
void	ft_putustr(wint_t *s);
void	ft_putstrl(char *str, int len);
int		count_width(const char *str);
int		count_stoi(const char *str);
int		someth_else(char c);
int		is_flag(char c);
int		deal_with_flags(t_info *info, const char *str, int i);
int		parse_flags(t_info *info, const char *str, int i);
int		parse_width(t_info *info, const char *str, int i);
int		parse_length(t_info *info, const char *str, int i);
int		print_percent(t_info *info, s_num n, const char *str, int i);
int		print_else(t_info *info, s_num n, const char *str, int i);
int		deal_with_types(t_info *info, s_num n, const char *str, int i);

#endif
