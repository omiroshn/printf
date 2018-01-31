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
# pragma pack(1)

typedef	struct		s_info
{
	int				res;
	char			sign_char;
	int				minus;
	int				plus;
	int				zero;
	int				resh;
	int				space;
	int				width;
	int				prec;
	int				size;
}					t_info;

int					ft_printf(const char *format, ...);

#endif
