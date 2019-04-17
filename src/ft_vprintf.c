/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:58:39 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/17 12:15:12 by zfaria           ###   ########.fr       */
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

t_dispatch	g_argdispatch[10] = {
	{'-', arg_leftalign},
	{'l', arg_long_inc},
	{'L', arg_long_inc},
	{'z', arg_long_max},
	{'j', arg_long_max},
	{'h', arg_short_inc},
	{'#', arg_altfmt},
	{' ', arg_spac},
	{'+', arg_all},
	{0, 0}
};

t_fmtarg	*getarg2(t_fmtarg *arg, char *temp, int i, int j)
{
	if (arg->precisionb)
		arg->precision = ft_atoi(temp);
	else
		arg->padding = ft_atoi(temp);
	arg->fstr = ft_strnew(j + 1);
	arg->fstr = ft_strncpy(arg->fstr, arg->fmt + i, j + 1);
	arg->funcc = arg->fmt[i + j];
	if (arg->funcc == 'u')
		arg->u = 1;
	else if (arg->funcc == '%')
	{
		arg->funcc = 'c';
		arg->perc = 1;
	}
	return (arg);
}

int			getarg1(t_fmtarg *arg, char *temp, int i, int j)
{
	int k;

	(void)temp;
	k = 0;
	while (g_argdispatch[k].fmt_func)
	{
		if (g_argdispatch[k].flag == arg->fmt[i + j])
		{
			g_argdispatch[k].fmt_func(arg, 0);
			return (1);
		}
		k++;
	}
	return (0);
}

t_fmtarg	*getarg(const char *fmt, int i)
{
	t_fmtarg	*arg;
	int			j;
	char		temp[20];

	j = 1;
	arg = ft_memalloc(sizeof(t_fmtarg));
	ft_bzero(temp, 20);
	arg->fmt = ft_strdup(fmt);
	while (fmt[i + j])
	{
		if (getarg1(arg, temp, i, j))
			;
		else if (fmt[i + j] == '0' && ft_strlen(temp) == 0 && !arg->precisionb)
			arg->zeroflag = 1;
		else if (fmt[i + j] >= '0' && fmt[i + j] <= '9')
			ft_strncat(temp, &fmt[i + j], 1);
		else if (fmt[i + j] == '.')
			arg_prec(arg, temp);
		else
			return (getarg2(arg, temp, i, j));
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
			return (g_dispatch[i].fmt_func(args, varg));
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
			if ((res = fire_dispatch(arg, varg)))
			{
				vectorcat(vector, res->str, res->bytes);
				freev(res->str, res, 0);
			}
			i += ft_strlen(arg->fstr);
			i += ft_strlen(arg->fstr) == 0 ? 1 : 0;
			freev(arg->fstr, arg->fmt, arg, 0);
		}
		else
			vectorcat(vector, fmt + i++, 1);
	}
	return (vector);
}
