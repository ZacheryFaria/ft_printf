/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:24:39 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/13 11:37:33 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>

static char	*handle_alt(t_fmtarg *arg, char *str)
{
	char	*news;
	int		len;

	len = ft_strlen(str);
	if (arg->allsign)
	{
		if (str[0] == '-')
			return (str);
		else
		{
			news = ft_memalloc(len + 2);
			news[0] = '+';
			ft_strcat(news, str);
			free(str);
			return (news);
		}
	}
	return (str);
}

static char	*handle_precision(t_fmtarg *arg, char *str)
{
	char	*news;
	int		len;
	int		digl;
	int		o;

	len = ft_strlen(str);
	o = 0;
	digl = len;
	if ((str[0] == '-' || str[0] == '+') && (o = 1))
		digl = len - 1;
	if (digl < arg->precision)
	{
		news = ft_memalloc(arg->precision + o + 1);
		ft_memset(news, '0', arg->precision + o);
		if (o)
			news[0] = str[0];
		ft_memcpy(news + o + (arg->precision - digl), str + o, len - o);
		free(str);
		return (news);
	}
	else if (arg->precision == 0 && arg->precisionb && str[0] == '0')
		return (ft_strdup(""));
	else if (arg->precision == 0 && arg->precisionb && str[0] == '+')
		return (ft_strdup("+"));
	else
		return (str);
}

static char	*handle_padding(t_fmtarg *arg, char *str)
{
	char	*news;
	int		len;
	int		o;
	int		sp;

	o = 0;
	sp = 0;
	len = ft_strlen(str);
	if (arg->padding > len)
	{
		news = ft_memalloc(arg->padding + 1);
		if (arg->zeroflag && !arg->leftalign && !(arg->precision -
			arg->padding < 0 && arg->precisionb))
			ft_memset(news, '0', arg->padding);
		else
			ft_memset(news, ' ', arg->padding);
		if ((str[0] == '-' || str[0] == '+') && !arg->leftalign && arg->zeroflag
			&& arg->precisionb && arg->precision - 1 >= 0 && (o = 1))
			news[arg->padding - len] = str[0];
		else if ((str[0] == '-' || str[0] == '+') && arg->leftalign && (o = 1))
			news[0] = str[0];
		else if ((str[0] == '-' || str[0] == '+') && arg->zeroflag && (o = 1))
			news[0] = str[0];
		else if (arg->spaceflag && !(str[0] == '-' || str[0] == '+') && (sp = 1))
			news[0] = ' ';
		if (arg->leftalign)
			ft_memcpy(news + o + sp, str + o, len - o);
		else if (arg->padding > 0)
			ft_memcpy(news + (arg->padding - len) + o, str + o, len - o);
		free(str);
	}
	else if (arg->spaceflag && !(str[0] == '-' || str[0] == '+'))
	{
		news = ft_memalloc(len + 2);
		news[0] = ' ';
		ft_strcat(news, str);
		free(str);
	}
	else
		return (str);
	return (news);
}

t_result	*fmt_d(t_fmtarg *arg, va_list varg)
{
	int64_t		val;
	t_result	*res;

	if (arg->longflag)
		val = va_arg(varg, uint64_t);
	else if (arg->shortflag == 1)
		val = (int16_t)va_arg(varg, int32_t);
	else if (arg->shortflag == 2)
		val = (int8_t)va_arg(varg, int32_t);
	else
		val = (int64_t)va_arg(varg, int32_t);
	res = malloc(sizeof(t_result));
	res->str = ft_itoa(val);
	res->str = handle_alt(arg, res->str);
	res->str = handle_precision(arg, res->str);
	res->str = handle_padding(arg, res->str);
	res->bytes = ft_strlen(res->str);
	return (res);
}
