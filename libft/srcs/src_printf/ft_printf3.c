/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:24:25 by apoque            #+#    #+#             */
/*   Updated: 2018/03/13 17:12:18 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_opt_size(t_printf *p)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isdigit(p->format[i]))
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(p->format[p->idx2]))
	{
		str[i] = p->format[p->idx2];
		p->idx2++;
		i++;
	}
	str[i] = '\0';
	p->size = ft_atoi(str);
	free(str);
}

void		ft_precision(t_printf *p)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isdigit(p->format[i]) && p->format[i] != '\0')
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(p->format[p->idx2]) && p->format[i] != '\0')
	{
		str[i] = p->format[p->idx2];
		p->idx2++;
		i++;
	}
	str[i] = '\0';
	p->precision = ft_atoi(str);
	free(str);
}

void		ft_opt_precision(t_printf *p)
{
	int	i;

	i = 0;
	if (p->format[p->idx2] == '.')
	{
		p->dot = 1;
		p->idx2++;
	}
	else
		return ;
	if (p->format[p->idx2] == '-' || !(ft_isdigit(p->format[p->idx2])))
		return ;
	ft_precision(p);
}

void		ft_opt_modif(t_printf *p)
{
	if (p->format[p->idx2] == 'h' && p->format[p->idx2 + 1] == 'h')
	{
		p->modif[HH] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == 'h')
		p->modif[H] = 1;
	else if (p->format[p->idx2] == 'l' && p->format[p->idx2 + 1] == 'l')
	{
		p->modif[LL] = 1;
		p->idx2++;
	}
	else if (p->format[p->idx2] == 'l')
		p->modif[L] = 1;
	else if (p->format[p->idx2] == 'j')
		p->modif[J] = 1;
	else if (p->format[p->idx2] == 'z')
		p->modif[Z] = 1;
	p->idx2++;
}
