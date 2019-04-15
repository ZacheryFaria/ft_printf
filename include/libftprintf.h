/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:46:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/15 13:24:37 by zfaria           ###   ########.fr       */
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
	int			perc;
}				t_fmtarg;

typedef struct	s_dispatch
{
	char		flag;
	void		*(*fmt_func)(t_fmtarg *, va_list);
}				t_dispatch;

typedef struct	s_vector
{
	size_t		cap;
	size_t		size;
	char		*v;
}				t_vector;

enum			e_types {
	H,
	HH,
	R,
	L,
	LL
};

t_vector		*make_vector(void);
t_vector		*vectorcat(t_vector *v, const char *str, size_t n);

int				ft_printf(const char *fmt, ...);
int				ft_fprintf(int fd, const char *fmt, ...);
int				ft_sprintf(char *str, const char *fmt, ...);

t_vector		*read_fmt_str(const char *fmt, va_list varg);

void			*fmt_c(t_fmtarg *arg, va_list varg);
void			*fmt_s(t_fmtarg *arg, va_list varg);
void			*fmt_p(t_fmtarg *arg, va_list varg);
void			*fmt_d(t_fmtarg *arg, va_list varg);

void			*cast_h(t_fmtarg *arg, va_list varg);
void			*cast_hh(t_fmtarg *arg, va_list varg);
void			*cast_reg(t_fmtarg *arg, va_list varg);
void			*cast_l(t_fmtarg *arg, va_list varg);
void			*cast_ll(t_fmtarg *arg, va_list varg);

#endif
