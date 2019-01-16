/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:43:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/16 13:43:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdarg.h>

char	*c(char *fmt, int c)
{
	char	*new;
	int		o;

	new = ft_strnew(ft_strlen(fmt));
	ft_memccpy(new, fmt, '%', ft_strlen(fmt));
	o = ft_strchri(fmt, '%');
	new[o] = c;
	ft_strcpy(&new[o + 1], &fmt[o + 2]);
	free(fmt);
	return (new);
}
