/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:43:18 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/16 14:06:13 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libftprintf.h>

char	*format(va_list args, char *outfmt, int flag)
{
	if (flag == e_c)
		return (c(outfmt, va_arg(args, int)));
	if (flag == e_d)
		return (d(outfmt, va_arg(args, int)));
	return (0);
}
