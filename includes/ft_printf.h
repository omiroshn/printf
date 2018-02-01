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
# pragma pack(1)

# define BIT7 127
# define BIT11 2047
# define BIT16 65535
# define BIT21 2097151
# define BIT26 67108863
# define BIT31 2147483647

int	g_count;

# define A(x) ((x) < 0 ? -(x) : (x))

typedef	struct		s_info
{
	va_list			list;
	int				res;

	int				minus;
	int				sign;
	int				zero;
	int				resh;
	int				space;

	int				width;
	int				prec;
	int				size;
	char			bukva;
}					t_info;

char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
char				*ft_strdup(char *src);
// void				*ft_memset(void *b, int c, size_t len);
// char				*ft_strdup(const char *s1);
// char				*ft_strjoin(char const *s1, char const *s2);
// char				*ft_strnew(size_t size);
// size_t				ft_strlen(const char *s);
// int					ft_tolower(int c);
// char				*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
