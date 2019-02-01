/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: z <z@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:50 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/01 14:02:52 by z                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>
#include <stdlib.h>

/*
** allowed: write, malloc, free, exit, stdarg(3)
*/

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	char		*str;
	t_dispatch	*table[2];

	va_start(args, fmt);
	table[0] = malloc(sizeof(t_dispatch));
	table[0]->fmt.fmt_c = &fmt_c;
	va_end(args);
	str = ft_strdup("Hello\n");
	ft_putstr(table[0]->fmt.fmt_c(str, 'a'));
	return (1);
}
