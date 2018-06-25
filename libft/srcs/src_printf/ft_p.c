/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:25:42 by apoque            #+#    #+#             */
/*   Updated: 2018/03/14 18:25:44 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_str(t_printf *p)
{
	char	*str;
	int		len;

	len = -1;
	if (p->txt == 1)
		ft_buf(p);
	if (p->dot == 1)
		len = p->precision;
	str = (char *)va_arg(p->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (len == -1 && str != NULL)
		p->buf = ft_strdup(str);
	else if (len != -1)
		p->buf = ft_strndup(str, len);
	p->size = p->size - ft_strlen(p->buf);
	if (p->size > 0 && p->flag[LESS] == 0)
		ft_put_space(p, 2);
	ft_buf(p);
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}

void	ft_p(t_printf *p)
{
	unsigned long	point;

	if (p->txt == 1)
		ft_buf(p);
	point = (unsigned long)va_arg(p->ap, void *);
	p->buf = ft_itoabase_u(point, "0123456789abcdef");
	p->size = p->size - ft_strlen(p->buf) - 2;
	p->flag[DIESE] = 1;
	p->flag[J] = -5;
	ft_print_x2(p, point, 0);
}

void	ft_put_space(t_printf *p, int flag)
{
	while (p->size != 0)
	{
		if (flag == 1)
			ft_putchar('0');
		if (flag == 2)
			ft_putchar(' ');
		p->len++;
		p->size--;
	}
}
