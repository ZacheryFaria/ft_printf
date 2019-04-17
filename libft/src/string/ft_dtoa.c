/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:39:55 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 20:09:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <math.h>

int		count_digits(int64_t n)
{
	int d;

	d = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_dtoa(long double d, int prec)
{
	char	*res;
	char	*temp;
	int		neg;
	uint64_t	sup;
	uint64_t	sub;
	int		point;
	int		zeroprec;
	int		i;
	int64_t	old;

	neg = 0;
	if (d < 0.0)
	{
		neg = 1;
		d = -d;
	}
	sup = (unsigned int)d;
	d -= sup;
	zeroprec = 0;
	i = 0;
	sub = 0;
	old = 0;
	while (d != 0 && i <= prec)
	{
		d *= 10;
		point = (int)d;
		if (!point && sub == 0)
			zeroprec++;
		sub *= 10;
		sub += point;
		d -= point;
		i++;
	}
	res = ft_strnew(33);
	temp = ft_strnew(20);
	old = sub;
	if (prec - zeroprec < count_digits(sub))
	{
		sub += 5;
		if (count_digits(old) < count_digits(sub) && zeroprec > 0)
			zeroprec--;
	}
	if (prec - zeroprec >= 0)
		ft_memset(temp, '0', zeroprec);
	if (prec - zeroprec > 0)
		ft_strncat(temp, ft_itoa(sub), prec - zeroprec);
	if (prec - zeroprec - count_digits(sub) > 0)
		ft_memset(temp + ft_strlen(temp), '0', prec - zeroprec - count_digits(sub));
	if (count_digits(old) != count_digits(sub) && !zeroprec && (temp[0] == '1' || temp[0] == 0))
	{
		sup++;
		ft_memmove(temp, temp + 1, ft_strlen(temp + 1));
	}
	ft_strcat(res, ft_itoa(sup));
	if (prec > 0)
	{
		ft_strcat(res, ".");
		if (ft_strlen(temp) == 0)
			ft_memset(temp, '0', prec);
		ft_strcat(res, temp);
	}
	if (neg)
	{
		ft_memmove(res + 1, res, ft_strlen(res));
		res[0] = '-';
	}
	return (res);
}
