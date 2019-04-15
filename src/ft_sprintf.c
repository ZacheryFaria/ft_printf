/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:59:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/15 11:01:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdarg.h>

int			ft_sprintf(char *str, const char *fmt, ...)
{
	va_list		args;
	int			res;
	t_vector	*vec;

	va_start(args, fmt);
	vec = read_fmt_str(fmt, args);
	va_end(args);
	str = vec->v;
	res = vec->size;
	free(vec->v);
	free(vec);
	return (res);
}
