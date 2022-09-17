/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2019/01/12 16:17:43 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"
#define SIZE sizeof(float)

float		ft_db(char *str, int i)
{
	float		nb;
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
		if (str[i] != '\0' && str[i] == '.')
			pt = 1;
		else if (pt == 0 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
			nb = nb + ft_power(10, power-- - 1) * (str[i] - 48);
		else if (pt == 1 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
			nb = nb + ft_negpower(j++) * (str[i] - 48);
		i++;
	}
	return (nb);
}

void		ft_get_info(t_comp *cp)
{
	t_info	info;
	int		flag;

	ft_bzero(&info, sizeof(t_info));
	while (cp->str[info.i] != '\0')
	{
		flag = 0;
		ft_iseq(cp->str, &(info.i), &(info.eq));
		ft_isneg(cp->str, &(info.i), &(info.neg));
		if (ft_isdigit(cp->str[info.i]) == 1)
		{
			ft_get_factor(cp, &info);
			flag++;
		}
		else if (cp->str[info.i] == 'X')
		{
			ft_get_power_bis(cp, &info);
			flag = 0;
		}
		if (flag == 1 && cp->str[info.i] != '*')
			cp->nb[info.eq][0] = info.nb;
		else if (cp->str[info.i] != '\0')
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

void		ft_treat(char *str, int detail)
{
	t_comp	cp;

	ft_bzero(&cp, sizeof(t_comp));
	cp.str = str;
	cp.power = ft_get_power(str);
	if (cp.power >= 0)
	{
		if (!(cp.nb[0] = (float *)ft_memalloc(SIZE * (cp.power + 1))))
			exit(EXIT_FAILURE);
		if (!(cp.nb[1] = (float *)ft_memalloc(SIZE * (cp.power + 1))))
			exit(EXIT_FAILURE);
		ft_get_info(&cp);
		ft_solve(&cp, detail);
		free(cp.nb[0]);
		free(cp.nb[1]);
	}
	else
		ft_printf("Wrong argument\n");
}

int			main(int ac, char **av)
{
	int	i;
	int	detail;

	i = 0;
	detail = 0;
	if (ac < 2)
		ft_printf("No argument given\n");
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i + 1], "-detail") == 0)
			detail = 1;
		else
			ft_treat(av[i + 1], detail);
		i++;
		if (ac > i + 1 && !(i == 1 && ft_strcmp(av[i], "-detail") == 0))
			ft_printf("\n");
	}
	return (0);
}
