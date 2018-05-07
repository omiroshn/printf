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
# include "libft.h"

#define _LONG 1
#define _UCHAR 2
#define _USHORTINT 3
#define _LONGLONG 4
#define _UINTMAXT 5
#define _SIZET 6

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
}					t_info;

int		ft_printf(const char *msg, ...);

#endif
