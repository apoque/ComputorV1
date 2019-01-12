/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2019/01/12 16:11:18 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define C cp->str[info->i]
#define S cp->str

void		ft_get_factor(t_comp *cp, t_info *info)
{
	info->nb = (info->neg == 0) ? ft_db(S, info->i) : -ft_db(S, info->i);
	info->neg = 0;
	while (C != '\0' && (ft_isdigit(C) == 1 || C == '.' || C == ' '))
		info->i++;
}

float		ft_float_square(float nb)
{
	float		res;
	short		limit;
	short		i;

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

float		ft_negpower(int i)
{
	float nb;

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
