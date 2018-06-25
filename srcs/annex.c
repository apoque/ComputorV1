/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2018/06/25 17:21:50 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

long double	ft_float_square(long double nb)
{
	long double		res;
	short			limit;
	short			i;

	res = 1;
	i = 1;
	limit = 100;
	if (nb <= 0)
		return (0);
	while (i < limit)
	{
		res = (res + nb / res) / 2;
		i++;
	}
	return (res);
}

long double	ft_negpower(int i)
{
	long double nb;

	nb = 1;
	while (i > 0)
	{
		nb = nb / 10;
		i--;
	}
	return (nb);
}

void		ft_isneg(char *str, int *i, short *neg)
{
	if (str[*i] != '\0' && str[*i] == '-')
	{
		*i = *i + 1;
		*neg = 1;
	}
}

void		ft_iseq(char *str, int *i, short *eq)
{
	if (str[*i] != '\0' && str[*i] == '=')
	{
		*i = *i + 1;
		*eq = 1;
	}
}
