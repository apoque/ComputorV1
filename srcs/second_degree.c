/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconde_degree                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2019/01/12 12:44:25 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define C cp->nb[0][0]
#define B cp->nb[0][1]
#define A cp->nb[0][2]
#define AFF "Discriminant is strictly "

void	ft_neg_disc(t_comp *cp, float disc)
{
	float		sol1;
	float		sol2;

	ft_printf("%snegative(%i), the two solutions are:\n", AFF, (int)disc);
	sol1 = -B / (2 * A);
	sol2 = ft_float_square(-disc) / (2 * A);
	ft_printfloat(sol1);
	ft_putstr(" + i * ");
	ft_printfloat(sol2);
	ft_putchar('\n');
	ft_printfloat(sol1);
	ft_putstr(" - i * ");
	ft_printfloat(sol2);
	ft_putchar('\n');
}

void	ft_pos_disc(t_comp *cp, float disc)
{
	float	sol;

	ft_printf("%spositive(%i), the two solutions are:\n", AFF, (int)disc);
	sol = (-B + ft_float_square(disc)) / (2 * A);
	ft_printfloat(sol);
	ft_putchar('\n');
	sol = (-B - ft_float_square(disc)) / (2 * A);
	ft_printfloat(sol);
	ft_putchar('\n');
}

void	ft_second_degree(t_comp *cp)
{
	float	disc;
	float	sol;

	disc = (B * B) - (4 * A * C);
	if (disc == 0)
	{
		ft_putstr("The solution is:\n");
		sol = -B / (2 * A);
		if ((int)B % (int)(2 * A) == 0)
			ft_printfloat(sol);
		else
		{
			ft_putnbr(-B / ft_get_pgcd(B, 2 * A));
			ft_putstr(" / ");
			ft_putnbr((2 * A) / ft_get_pgcd(B, 2 * A));
		}
		ft_putchar('\n');
	}
	else if (disc > 0)
		ft_pos_disc(cp, disc);
	else
		ft_neg_disc(cp, disc);
}
