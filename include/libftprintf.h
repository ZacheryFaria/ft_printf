/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:46:04 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/18 15:38:38 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

enum	e_fmt_flag
{
	e_c = 1,
	e_d
};

int		ft_printf(const char *fmt, ...);

char	*ft_vprintf(char *fmt, va_list args);
char	*format(char *fmt, va_list args);
char	*parse(char *fml, va_list args, int flag);
int		get_flag(char *str);

char	*c(char *fmt, char c);
char	*d(char *fmt, int d);

#endif
