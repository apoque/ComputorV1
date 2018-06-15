/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:07 by apoque            #+#    #+#             */
/*   Updated: 2018/06/15 19:17:57 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

long double	ft_negpower(int i)
{
	long double nb;

	nb = 1;
	while (i > 0)
	{
		nb = nb / 10;
		i--;
	}
	return (nb);
}

long double	ft_get_double(char *str, int i)
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
		printf("char = [%c] et i = %i\n", str[i], i);
		if (str[i] !='\0' && str[i] == '.')
			pt = 1;
		else if (pt == 0 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
		{
		printf("nb = [%f]\n", (double)nb);
			nb = nb + ft_power(10, power - 1) * (str[i] - 48);
		printf("nb = [%f]\n", (double)nb);
			power--;
		}
		else if (pt == 1 && str[i] != '\0' && ft_isdigit(str[i]) == 1)
		{
		printf("nb = [%f]\n", (double)nb);
			nb = nb + ft_negpower(j) * (str[i] - 48);
		printf("nb = [%f]\n", (double)nb);
			j++;
		printf("char = [%c] et i = %i\n", str[i], i);
		}
		i++;
		printf("char = [%c] et i = %i\n", str[i], i);
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
	while (i < 3)
	{
		printf("nb1^%i = %f\n", i, (double)cp->nb1[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("nb2^%i = %f\n", i, (double)cp->nb2[i]);
		i++;
	}
	ft_printf("____________________\n\n");
}

void		ft_get_info(t_comp *cp)
{
	int			i;
	long double	nb;
	int			power;
	short		eq;

	i = 0;
	eq = 0;
	while (cp->str[i] != '\0' && cp->str[i] != '=')
	{
		if (cp->str[i] == '=')
			eq = 1;
		else if (ft_isdigit(cp->str[i]) == 1)
			nb = ft_get_double(cp->str, i);
		else if (cp->str[i] == 'X')
		{
			i = i + 2;
			power = ft_atoi(&cp->str[i]);
			if (eq == 0)
				cp->nb1[power] = nb;
			else
				cp->nb2[power] = nb;
		}
		i++;
	}
	ft_display_info(cp);
}

int			ft_get_power(char *str)
{
	int	len;
	int	power;
	int	i;

	i = 0;
	power = -1;
	len = ft_strlen(str);
	while (str[i] != '\0' && i < len)
	{
		while (str[i] != 'X' && str[i] != '\0' && i < len)
			i++;
		if (str[i] == 'X' && str[i + 1] == '^')
		{
			if (power < ft_atoi(&str[i + 2]))
				power = ft_atoi(&str[i + 2]);
		}
		else if (str[i] == 'X')
		{
			if (power < 1)
				power = 1;
		}
		i++;
	}
	return (power);
}

void		ft_treatment(char *str)
{
	t_comp	cp;

	ft_bzero(&cp, sizeof(t_comp));
	cp.str = str;
	cp.power = ft_get_power(str);
	if (cp.power > 2)
		ft_printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
	else if (cp.power >= 0 && cp.power <= 2)
	{
		ft_get_info(&cp);
		//ft_solve(&cp);
		//ft_display_res(&cp);
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
		ft_treatment(av[i + 1]);
		i++;
		if (ac > i + 1)
			ft_printf("\n");
	}
	return (0);
}
