/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:24:05 by apoque            #+#    #+#             */
/*   Updated: 2018/03/13 13:24:07 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_percent(t_printf *p)
{
	if (p->txt == 1)
		ft_buf(p);
	p->size--;
	if (p->size > 0 && p->flag[ZERO] == 1 && p->flag[LESS] != 1)
		ft_put_space(p, 1);
	if (p->size > 0 && p->flag[LESS] != 1)
		ft_put_space(p, 2);
	ft_putchar('%');
	p->len++;
	if (p->size > 0 && p->flag[LESS] == 1)
		ft_put_space(p, 2);
}
