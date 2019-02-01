/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <z@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:46:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/01 14:00:58 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int				ft_printf(const char *fmt, ...);

char			*fmt_c(char *str, char c);
char			*fmt_s(char *fmt, char *str);

typedef union	u_func
{
	char		*(*fmt_c)(char *, char);	
	char		*(*fmt_s)(char *, char *);
}				t_func;

typedef struct	s_dispatch
{
	char		symb;
	t_func		fmt;
}				t_dispatch;

#endif
