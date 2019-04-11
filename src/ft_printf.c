/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:50 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/11 11:42:45 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>
#include <stdlib.h>
#include <unistd.h>

void printarg(t_fmtarg arg)
{
	printf("allsign: %d\nleftalign: %d\nlongflag: %d\npadding: %d\nprecision: %d\nprecisionb: %d\nshortflag: %d\nzeroflag: %d\n", 
		arg.allsign, arg.leftalign, arg.longflag, arg.padding,
		arg.precision, arg.precisionb, arg.shortflag, arg.zeroflag);
}

t_fmtarg	getarg(const char *fmt, int i)
{
	t_fmtarg	arg;
	int			j;
	char		temp[20];

	j = 1;
	while (fmt[i + j])
	{
		if (fmt[i + j] == '-')
			arg.leftalign = 1;
		else if (fmt[i + j] == '0' && ft_strlen(temp) == 0)
			arg.zeroflag = 1;
		else if (fmt[i + j] >= '0' && fmt[i + j] <= '9')
			ft_strncat(temp, &fmt[i + j], 1);
		else if (fmt[i + j] == '+')
			arg.allsign = 1;
		else if (fmt[i + j] == 'l')
			arg.longflag++;
		else if (fmt[i + j] == 'h')
			arg.shortflag++;
		else if (fmt[i + j] == ' ')
			arg.spaceflag = 1;
		else if (fmt[i + j] == '.')
		{
			arg.precisionb = 1;
			arg.padding = ft_atoi(temp);
			ft_strclr(temp);
		}
		else
		{
			arg.precision = ft_atoi(temp);
			arg.fstr = ft_strnew(j + 1);
			arg.fstr = ft_strncpy(arg.fstr, fmt + i, j + 1);
			return (arg);
		}
		j++;
	}
	return (arg);	
}

int			read_fmt_str(const char *fmt, va_list args)
{
	int			i;
	int			bwrite;
	t_fmtarg	arg;
	(void)args;

	i = 0;
	bwrite = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			arg = getarg(fmt, i);
			printarg(arg);
			i += ft_strlen(arg.fstr) - 1;
			printf(":%s:", arg.fstr);
		}
		else
		{
			bwrite += write(1, &fmt[i], 1);
		}
		i++;
	}
	return (bwrite);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			res;

	va_start(args, fmt);
	res = read_fmt_str(fmt, args);
	va_end(args);
	return (res);
}
