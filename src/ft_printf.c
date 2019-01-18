/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:50 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/18 09:40:11 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>

/*
** allowed: write, malloc, free, exit, stdarg(3)
*/

int	nextflag(char *fmt)
{
	while (*fmt != 0)
	{
		if (*fmt == '%')
		{
			if (*(fmt + 1) == 'c')
				return (e_c);
			else if (*(fmt + 1) == 'd')
				return (e_d);
		}
		fmt++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	char		*outfmt;
	va_list		args;
	int			flag;

	va_start(args, fmt);
	outfmt = ft_strdup(fmt);
	while ((flag = nextflag(outfmt)))
		outfmt = format(args, outfmt, flag);
	ft_putstr(outfmt);
	va_end(args);
	return (ft_strlen(outfmt));
}
