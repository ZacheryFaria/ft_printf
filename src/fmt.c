/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:43:18 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/18 15:41:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <libftprintf.h>

char	*format(char *fmt, va_list args)
{
	char	*p;
	int		flag;

	if (!ft_strchr(fmt, '%'))
		return (fmt);
	p = ft_strchr(fmt, '%');
	flag = get_flag(p);
	if (flag > 0)
		fmt = parse(fmt, args, flag);
	return (format(fmt, args));
}

char	*parse(char *fmt, va_list args, int flag)
{
	if (flag == e_c)
		return (c(fmt, va_arg(args, int)));
	return (fmt);	 
}

int		get_flag(char *str)
{
	str++;
	if (*str == 'c')
		return (e_c);
	return (0);
}