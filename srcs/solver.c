/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2018/06/15 19:17:57 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define MSG "The polynomial degree is stricly greater than 2, I can't solve.\n"

void	ft_printfloat(long double nb)
{
	short	is_decimal;
	int		nb_bis;

	is_decimal = ((nb - (int)nb > 0) ? 1 : 0);
	ft_putnbr((int)nb);
	(is_decimal == 1) ? ft_putchar('.') : is_decimal++;
	nb_bis = (int)((nb - (int)nb) * 1000000);
	if (nb_bis % 10 == 9)
		nb_bis++;
	while (nb_bis % 10 == 0 && nb_bis != 0)
		nb_bis = nb_bis / 10;
	if (nb_bis != 0)
		ft_putnbr(nb_bis);
}

void	ft_first_degree(t_comp *cp)
{
	long double	nb;

	nb = -cp->nb[0][0] / cp->nb[0][1];
	ft_putstr("The solution is:\n");
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	ft_printfloat(nb);
	ft_putchar('\n');
}

void	ft_dispatch(t_comp *cp)
{
	if (cp->new_power > 2)
		ft_putstr(MSG);
	else if (cp->new_power == 1)
		ft_first_degree(cp);
	else if (cp->new_power == 0)
	{
		if (cp->nb[0][0] == 0)
			ft_putstr("The solution is the whole set of real numbers R\n");
		else
			ft_putstr("There is no solution to this equation\n");
	}
	else
		ft_second_degree(cp);
}

void	ft_print_reduced_form(t_comp *cp)
{
	int		i;
	int		neg;
	short	first;

	i = -1;
	first = 0;
	ft_putstr("Reduced form: ");
	while (++i <= cp->new_power)
	{
		neg = 0;
		if (i == 0 || cp->nb[0][i] > 0)
		{
			(first == 0) ? first = 1 : ft_printf("+ ");
			ft_printfloat(cp->nb[0][i]);
			ft_printf(" * X^%i ", i);
		}
		else if (i == 0 || cp->nb[0][i] < 0)
		{
			(first == 0) ? ft_printf("-") : ft_printf("- ");
			ft_printfloat(-cp->nb[0][i]);
			ft_printf(" * X^%i ", i);
			first = 1;
		}
	}
	ft_putstr("= 0\n");
}

void	ft_solve(t_comp *cp)
{
	int	i;

	i = 0;
	while (i <= cp->power)
	{
		cp->nb[0][i] = cp->nb[0][i] - cp->nb[1][i];
		i++;
	}
	i = cp->power;
	while (i < 0 && cp->nb[0][i] == 0)
		i--;
	cp->new_power = i;
	ft_print_reduced_form(cp);
	ft_printf("Polynomial degree: %i\n", cp->new_power);
	ft_dispatch(cp);
}
