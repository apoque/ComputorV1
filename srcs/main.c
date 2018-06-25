/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2018/06/25 14:12:08 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define S cp->str

long double	ft_db(char *str, int i)
{
	long double	nb;
	short		pt;
	int			j;
	int			power;

	power = 0;
	nb = 0;
	j = i;
	pt = 0;
	while (str[j] != '\0' && ft_isdigit(str[j]) == 1)
		j++;
	power = j - i;
	j = 1;
	while (str[i] != '\0' && (ft_isdigit(str[i]) == 1 || str[i] == '.'))
	{
		if (str[i] !='\0' && str[i] == '.')
			pt = 1;
		else if (pt == 0 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
		{
			nb = nb + ft_power(10, power - 1) * (str[i] - 48);
			power--;
		}
		else if (pt == 1 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
		{
			nb = nb + ft_negpower(j) * (str[i] - 48);
			j++;
		}
		i++;
	}
	return (nb);
}

void		ft_display_info(t_comp *cp)
{
	ft_printf("_______INFO_________\n\n");
	ft_printf("str = [%s]\n", cp->str);
	ft_printf("power max = %i\n", cp->power);
	int i;
	i = 0;
	while (i <= cp->power)
	{
		printf("nb1^%i = %f\n", i, (double)cp->nb[0][i]);
		i++;
	}
	i = 0;
	while (i <= cp->power)
	{
		printf("nb2^%i = %f\n", i, (double)cp->nb[1][i]);
		i++;
	}
	ft_printf("____________________\n\n");
}

void		ft_get_info(t_comp *cp)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	while (cp->str[info.i] != '\0')
	{
		ft_iseq(cp->str, &(info.i), &(info.eq));
		ft_isneg(cp->str, &(info.i), &(info.neg));
		if (ft_isdigit(cp->str[info.i]) == 1)
		{
			info.nb = (info.neg == 0) ? ft_db(S, info.i) : -ft_db(S, info.i);
			info.neg = 0;
			while (cp->str[info.i] != '\0' &&
				(ft_isdigit(cp->str[info.i]) == 1 || cp->str[info.i] == '.'))
				info.i++;
		}
		else if (cp->str[info.i] == 'X')
		{
			info.i = info.i + 2;
			info.power = ft_atoi(&cp->str[info.i]);
			while (cp->str[info.i] != '\0' && ft_isdigit(cp->str[info.i]) == 1)
				info.i++;
			cp->nb[info.eq][info.power] = info.nb;
		}
		else
			info.i++;
	}
}

int			ft_get_power(char *str)
{
	int	len;
	int	power;
	int	i;

	i = -1;
	power = -1;
	len = ft_strlen(str);
	while (str[++i] != '\0' && i < len)
	{
		while (str[i] != 'X' && str[i] != '\0' && i < len)
			i++;
		if (str[i] == 'X' && str[i + 1] == '^')
		{
			if (power < ft_atoi(&str[i + 2]))
				power = ft_atoi(&str[i + 2]);
			while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
				i++;
		}
		else if (str[i] == 'X')
		{
			if (power < 1)
				power = 1;
		}
	}
	return (power);
}

void		ft_treat(char *str)
{
	t_comp	cp;

	ft_bzero(&cp, sizeof(t_comp));
	cp.str = str;
	cp.power = ft_get_power(str);
	if (cp.power >= 0)
	{
		if (!(cp.nb[0] = (long double *)ft_memalloc(sizeof(long double) * (cp.power + 1))))
			exit(EXIT_FAILURE);
		if (!(cp.nb[1] = (long double *)ft_memalloc(sizeof(long double) * (cp.power + 1))))
			exit(EXIT_FAILURE);
		ft_get_info(&cp);
		ft_solve(&cp);
		free(cp.nb[0]);
		free(cp.nb[1]);
		//free(cp.nb);
	}
	else
		ft_printf("Wrong argument\n");
}

int			main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		ft_printf("No argument given\n");
	while (i < ac - 1)
	{
		ft_treat(av[i + 1]);
		i++;
		if (ac > i + 1)
			ft_printf("\n");
	}
	return (0);
}
