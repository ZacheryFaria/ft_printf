/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:50 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/18 15:41:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>

/*
** allowed: write, malloc, free, exit, stdarg(3)
*/

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	char		*str;

	va_start(args, fmt);
	str = format((char *)fmt, args);
	va_end(args);
	ft_putstr(str);
	return (1);
}
