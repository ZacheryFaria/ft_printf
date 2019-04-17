/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:58:39 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 20:42:35 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>
#include <stdlib.h>
#include <unistd.h>

t_dispatch	g_dispatch[16] = {
	{'s', fmt_s},
	{'c', fmt_c},
	{'d', fmt_d},
	{'i', fmt_d},
	{'u', fmt_d},
	{'x', fmt_x},
	{'X', fmt_x},
	{'o', fmt_o},
	{'O', fmt_o},
	{'p', fmt_p},
	{'b', fmt_b},
	{'v', fmt_v},
	{'f', fmt_f},
	{'F', fmt_f},
	{0, 0}
};

t_fmtarg	*getarg(const char *fmt, int i)
{
	t_fmtarg	*arg;
	int			j;
	char		temp[20];

	j = 1;
	arg = ft_memalloc(sizeof(t_fmtarg));
	ft_bzero(temp, 20);
	while (fmt[i + j])
	{
		if (fmt[i + j] == '-')
			arg->leftalign = 1;
		else if (fmt[i + j] == '0' && ft_strlen(temp) == 0 && !arg->precisionb)
			arg->zeroflag = 1;
		else if (fmt[i + j] >= '0' && fmt[i + j] <= '9')
			ft_strncat(temp, &fmt[i + j], 1);
		else if (fmt[i + j] == '+')
			arg->allsign = 1;
		else if (fmt[i + j] == 'l' || fmt[i + j] == 'L')
			arg->longflag++;
		else if (fmt[i + j] == 'h')
			arg->shortflag++;
		else if (fmt[i + j] == 'j')
			arg->longflag = 2;
		else if (fmt[i + j] == 'z')
			arg->longflag = 2;
		else if (fmt[i + j] == ' ')
			arg->spaceflag = 1;
		else if (fmt[i + j] == '#')
			arg->altfmt = 1;
		else if (fmt[i + j] == '.')
		{
			arg->precisionb = 1;
			arg->padding = ft_atoi(temp);
			ft_strclr(temp);
		}
		else
		{
			if (arg->precisionb)
				arg->precision = ft_atoi(temp);
			else
				arg->padding = ft_atoi(temp);
			arg->fstr = ft_strnew(j + 1);
			arg->fstr = ft_strncpy(arg->fstr, fmt + i, j + 1);
			arg->funcc = fmt[i + j];
			if (arg->funcc == 'u')
				arg->u = 1;
			else if (arg->funcc == '%')
			{
				arg->funcc = 'c';
				arg->perc = 1;
			}
			return (arg);
		}
		j++;
	}
	return (arg);	
}

t_result	*fire_dispatch(t_fmtarg *args, va_list varg)
{
	int i;
	
	i = 0;
	while (g_dispatch[i].fmt_func)
	{
		if (args->funcc == g_dispatch[i].flag)
		{
			return(g_dispatch[i].fmt_func(args, varg));
		}
		i++;
	}
	return (0);
}

t_vector	*read_fmt_str(const char *fmt, va_list varg)
{
	int			i;
	t_vector	*vector;
	t_fmtarg	*arg;
	t_result	*res;

	i = 0;
	vector = make_vector();
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			arg = getarg(fmt, i);
			res = fire_dispatch(arg, varg);
			if (res)
			{
				vectorcat(vector, res->str, res->bytes);
				free(res->str);
				free(res);
			}
			i += ft_strlen(arg->fstr) - 1;
			free(arg->fstr);
			free(arg);
			arg = 0;
		}
		else
			vectorcat(vector, fmt + i, 1);
		i++;
	}
	return (vector);
}
