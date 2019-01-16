/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:59:43 by awindham          #+#    #+#             */
/*   Updated: 2019/01/16 14:08:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

enum	e_fmt_flag
{
	e_c,
	e_d
};

int		ft_printf(const char *fmt, ...);

char	*format(va_list args, char *outfmt, int flag);
char	*c(char *fmt, int c);
char	*d(char *fmt, int d);

#endif
