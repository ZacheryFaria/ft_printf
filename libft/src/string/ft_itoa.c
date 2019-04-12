/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:25:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/12 11:41:57 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int64_t n)
{
	char			*res;
	int				i;
	uint64_t		num;

	if (n == 0 && !(i = 0))
		return (ft_strdup("0"));
	res = ft_strnew(33);
	i = 0;
	if (res)
	{
		if (n < 0)
			num = n * -1;
		else
			num = n;
		while (num > 0)
		{
			res[i++] = num % 10 + '0';
			num /= 10;
		}
		if (n < 0)
			res[i++] = '-';
		else
			res[i] = 0;
		ft_strrev((unsigned char *)res);
	}
	return (res);
}
