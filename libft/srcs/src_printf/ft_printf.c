/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:11:11 by apoque            #+#    #+#             */
/*   Updated: 2018/06/25 14:05:53 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define F p->format[p->idx2]

void		ft_treatment(t_printf *p)
{
	int	a;

	a = 1;
	if ((F == 'u' && p->modif[L] != 1 && p->modif[LL] != 1) ||
			((F == 'd' || F == 'i') && p->modif[Z] == 1))
		ft_uint(p);
	else if (F == 'x')
		ft_xint(p);
	else if (F == 'X')
		ft_xmajint(p);
	else if (F == 'o' && p->modif[LL] != 1 && p->modif[L] != 1)
		ft_oint(p);
	else if (F == 'O' || F == 'o')
		ft_omajint(p);
	else if (F == 'D' || ((F == 'd' || F == 'i') &&
				(p->modif[L] == 1 || p->modif[LL] == 1 || p->modif[J] == 1)))
		ft_long(p);
	else if (F == 's' && p->modif[L] != 1)
		ft_str(p);
	else
	{
		a = 0;
		ft_treatment2(p);
	}
	(a == 1) ? p->idx2++ : a--;
}

void		ft_txt(t_printf *p)
{
	char	*tmp;
	int		i;

	i = 0;
	p->txt = 1;
	tmp = (char *)malloc(sizeof(char) * (p->idx2 - p->idx1 + 1));
	tmp[p->idx2 - p->idx1] = '\0';
	while (p->idx1 < p->idx2)
	{
		tmp[i] = p->format[p->idx1];
		p->idx1++;
		i++;
	}
	p->buf = ft_strdup(tmp);
	free(tmp);
}

void		ft_buf(t_printf *p)
{
	p->len = p->len + ft_strlen(p->buf);
	ft_putstr(p->buf);
	if (p->buf != NULL && F != 'c' && F != 'C')
	{
		free(p->buf);
		p->buf = NULL;
	}
	else
		free(p->buf);
}

void		ft_init_p(t_printf *p, const char *format)
{
	p->buf = NULL;
	p->idx1 = 0;
	p->idx2 = 0;
	p->len = 0;
	p->error = 0;
	p->format = format;
}

int			ft_printf(const char *format, ...)
{
	t_printf p;

	ft_init_p(&p, format);
	va_start(p.ap, format);
	while (p.format[p.idx1] && p.error != -1)
	{
		p.idx1 = p.idx2;
		p.txt = 0;
		while (p.format[p.idx2] != '%' && p.format[p.idx2] != '\0')
			p.idx2++;
		if (p.idx1 != p.idx2)
			ft_txt(&p);
		if (p.format[p.idx2++] == '%')
		{
			ft_init_opt(&p);
			ft_opt(&p);
			ft_treatment(&p);
		}
		if (p.txt == 1 && p.idx1 == (int)ft_strlen((char *)p.format))
			ft_buf(&p);
	}
	va_end(p.ap);
	return (p.len = (p.error != -1) ? p.len : -1);
}
