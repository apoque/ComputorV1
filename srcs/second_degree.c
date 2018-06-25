/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seconde_degree                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2018/06/15 19:17:57 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define C cp->nb[0][0]
#define B cp->nb[0][1]
#define A cp->nb[0][2]



void	ft_neg_disc(t_comp *cp, long double disc)
{
	long double	sol1;
	long double	sol2;

	ft_putstr("Discriminant is strictly negative, the two solutions are:\n");
	sol1 = -B / ( 2 * A);
	sol2 = ft_float_square(-disc) / (2 * A);
		if (sol1 < 0)
	{
		ft_putchar('-');
		sol1 = -sol1;
	}
	ft_printfloat(sol1);
	ft_putstr(" + i * ");
	if (sol2 < 0)
	{
		ft_putchar('-');
		sol2 = -sol2;
	}
	ft_printfloat(sol2);
	ft_putchar('\n');
	ft_printfloat(sol1);
	ft_putstr(" - i * ");
	ft_printfloat(sol2);
	ft_putchar('\n');
}

void	ft_pos_disc(t_comp *cp, long double disc)
{
	long double	sol;

	ft_putstr("Discriminant is strictly positive, the two solutions are:\n");
	sol = (-B + ft_float_square(disc)) / (2 * A);
	if (sol < 0)
	{
		ft_putchar('-');
		sol = -sol;
	}
	ft_printfloat(sol);
	ft_putchar('\n');
	sol = (-B - ft_float_square(disc)) / (2 * A);
	if (sol < 0)
	{
		ft_putchar('-');
		sol = -sol;
	}
	ft_printfloat(sol);
	ft_putchar('\n');
}

void	ft_second_degree(t_comp *cp)
{
	long double	disc;
	long double	sol;

	disc = (B * B) - (4 * A * C);
	if (disc == 0)
	{
		sol = -B / ( 2 * A);
		ft_putstr("The solution is:\n");
		if (sol < 0)
		{
			ft_putchar('-');
			sol = -sol;
		}
		ft_printfloat(sol);
		ft_putchar('\n');
	}
	else if (disc > 0)
		ft_pos_disc(cp, disc);
	else
		ft_neg_disc(cp, disc);
}
