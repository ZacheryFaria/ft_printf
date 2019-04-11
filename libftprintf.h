/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:46:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/11 11:42:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct	s_dispatch
{
	char		*flag;
	char		*(*fmt_func)();
}				t_dispatch;

typedef struct	s_fmtarg
{
	char		*fstr;
	char		*vstr;
	int			leftalign;
	int			padding;
	int			precision;
	int			precisionb;
	int			allsign;
	int			longflag;
	int			shortflag;
	int			zeroflag;
	int			spaceflag;
}				t_fmtarg;

typedef struct	s_fireres
{
	char		*str;
	int			bytes;
	int			offset;
}				t_fireres;

int				ft_printf(const char *fmt, ...);

char			*fmt_c(char *str, char *c);
char			*fmt_s(char *fmt, char *str);

#endif
