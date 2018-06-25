/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:14:51 by apoque            #+#    #+#             */
/*   Updated: 2018/03/14 18:26:24 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define F p->format[p->idx2]

void		ft_treatment2(t_printf *p)
{
	int	a;

	a = 1;
	if (F == 'i' || F == 'd')
		ft_int(p);
	else if (F == 'S' || (F == 's' && p->modif[L] == 1))
		ft_wstr(p);
	else if (F == 'c' && p->modif[L] == 0)
		ft_char(p);
	else if (F == 'U' || (F == 'u' && (p->modif[L] == 1 || p->modif[LL] == 1)))
		ft_umajint(p);
	else if (F == 'C' || (F == 'c' && p->modif[L] == 1))
		ft_wchar(p);
	else if (F == 'p')
		ft_p(p);
	else if (F == '%')
		ft_percent(p);
	else
		a = 0;
	if (a == 1)
		p->idx2++;
}

void		ft_init_opt(t_printf *p)
{
	int	i;

	i = 0;
	while (i != 5)
	{
		p->flag[i] = 0;
		i++;
	}
	i = 0;
	while (i != 6)
	{
		p->modif[i] = 0;
		i++;
	}
	p->dot = 0;
	p->precision = 0;
	p->size = 0;
}

void		ft_opt_flag(t_printf *p)
{
	if (F == '#')
	{
		p->flag[DIESE] = 1;
		p->idx2++;
	}
	else if (F == '0')
	{
		p->flag[ZERO] = 1;
		p->idx2++;
	}
	else if (F == '-')
	{
		p->flag[LESS] = 1;
		p->idx2++;
	}
	else if (F == '+')
	{
		p->flag[MORE] = 1;
		p->idx2++;
	}
	else if (F == ' ')
	{
		p->flag[SPACE] = 1;
		p->idx2++;
	}
}

void		ft_opt_specifier(t_printf *p)
{
	if ((F == '-' || F == '+' ||
				F == '#' || F == '0' ||
				F == ' '))
		ft_opt_flag(p);
	if (ft_isdigit(F) && F != '0')
		ft_opt_size(p);
	if (F == 'h' || F == 'l' ||
			F == 'j' || F == 'z')
		ft_opt_modif(p);
	if (F == '.')
		ft_opt_precision(p);
}

int			ft_opt(t_printf *p)
{
	if (p->format[p->idx1 + 1] == '%' || F == '\0')
		return (1);
	while ((F == '-' || F == '+' ||
				F == '#' || F == '0' ||
				F == ' ' || F == 'h' ||
				F == 'l' || F == 'j' ||
				F == 'z' || F == '.' ||
				(ft_isdigit(F))) && F != '\0')
		ft_opt_specifier(p);
	return (1);
}
