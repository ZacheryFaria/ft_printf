/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:59:04 by z                 #+#    #+#             */
/*   Updated: 2019/04/11 17:41:19 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>
#include <libft.h>

static void	handle_padding(t_fmtarg *arg, t_result *res, char c)
{
	char	*news;

	if (arg->padding > 1)
	{
		res->bytes = arg->padding;
		news = ft_memalloc(arg->padding);
		news = ft_memset(news, ' ', arg->padding);
		if (arg->leftalign)
			news[0] = c;
		else
			news[arg->padding - 1] = c;
		res->str = news;
	}
}

t_result	*fmt_c(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	char		astr;

	res = malloc(sizeof(t_result));
	astr = va_arg(varg, int);
	handle_padding(arg, res, astr);
	return (res);
}
