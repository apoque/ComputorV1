/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2019/01/12 16:11:29 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define A cp->nb[0][2]
#define B cp->nb[0][1]
#define C cp->nb[0][0]

#define D cp->nb[1][2]
#define E cp->nb[1][1]
#define F cp->nb[1][0]

void	ft_display_detail_bis(t_comp *cp, int i)
{
	if (i == 0 && E != 0)
	{
		ft_putnbr(E);
		ft_putstr(" * X^1 ");
	}
	if (cp->nb[1][2] != 0)
	{
		if (i == 0 && D > 0 && E != 0)
			ft_putstr("+ ");
		ft_putnbr(D);
		ft_putstr(" * X^2");
	}
	else
		ft_putstr(" 0");
}

void	ft_display_detail(t_comp *cp, int i)
{
	ft_putnbr(cp->nb[0][0]);
	ft_putstr(" * X^0 ");
	if (B > 0 && cp->power > 0)
		ft_putstr("+ ");
	ft_putnbr(B);
	ft_putstr(" * X^1 ");
	if (A > 0 && cp->power > 1)
		ft_putstr("+ ");
	ft_putnbr(A);
	ft_putstr(" * X^2 = ");
	if (i == cp->power)
		ft_putstr(" 0");
	else
		ft_display_detail_bis(cp, i);
	ft_putchar('\n');
}

void	ft_get_power_bis(t_comp *cp, t_info *info)
{
	if (cp->str[info->i + 1] == '^')
	{
		info->i = info->i + 2;
		info->power = ft_atoi(&cp->str[info->i]);
		while (cp->str[info->i] != '\0' && ft_isdigit(cp->str[info->i]) == 1)
			info->i++;
		cp->nb[info->eq][info->power] = info->nb;
	}
	else
	{
		cp->nb[info->eq][1] = info->nb;
		info->i++;
	}
}
