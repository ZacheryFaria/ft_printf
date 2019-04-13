/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:46:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/13 14:31:06 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_result
{
	char		*str;
	int			bytes;
}				t_result;

typedef struct	s_dispatch
{
	char		flag;
	void		*(*fmt_func)();
}				t_dispatch;

typedef struct	s_fmtarg
{
	char		*fstr;
	char		*vstr;
	char		funcc;
	int			leftalign;
	int			padding;
	int			precision;
	int			precisionb;
	int			allsign;
	int			longflag;
	int			shortflag;
	int			zeroflag;
	int			spaceflag;
	int			altfmt;
	int			u;
}				t_fmtarg;

typedef struct	s_vector
{
	size_t		cap;
	size_t		size;
	char		*v;
}				t_vector;

t_vector		*make_vector(void);
t_vector		*vectorcat(t_vector *v, const char *str, size_t n);

int				ft_printf(const char *fmt, ...);

t_result		*fmt_c(t_fmtarg *arg, va_list varg);
t_result		*fmt_s(t_fmtarg *arg, va_list varg);
t_result		*fmt_p(t_fmtarg *arg, va_list varg);
t_result		*fmt_d(t_fmtarg *arg, va_list varg);

void			*cast_h(t_fmtarg *arg, va_list varg);
void			*cast_hh(t_fmtarg *arg, va_list varg);
void			*cast_reg(t_fmtarg *arg, va_list varg);
void			*cast_l(t_fmtarg *arg, va_list varg);
void			*cast_ll(t_fmtarg *arg, va_list varg);

#endif
