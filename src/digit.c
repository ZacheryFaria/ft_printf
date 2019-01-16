/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:43:03 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/16 13:43:05 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*d(char *fmt, int d)
{
	char	*new;
	char	*p;

	new = ft_strnew(999);
	ft_memccpy(new, fmt, '%', ft_strlen(fmt));
	ft_memccpy(new + ft_strchri(new, '%'), ft_itoa(d), 0, SIZE_MAX);
	fmt = ft_strchr(fmt, '%');
	p = ft_strchr(new, 0);
	ft_memccpy(p, fmt, 0, 1);
	return (new);
}
