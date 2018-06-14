//HEADER
//
//
//
//
//
//
//
//
//

#include "computorv1.h"

void	ft_get_info(t_comp *cp)
{
	int	i;

	i = 0;
	while (cp->str[i] != '\0')
	{
		i++;
	}
}

int		ft_get_power(char *str)
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

void	ft_treatment(char *str)
{
	t_comp	cp;

	ft_bzero(&cp, sizeof(t_comp));
	cp.str = str;
	cp.power = ft_get_power(str);
	ft_printf("power = %i\n", cp.power);
	ft_printf("[%s]\n", cp.str);
	if (cp.power > 2)
		ft_printf("The polynomial degree is strictly greater than 2, I can't solve.\n");
	else if (cp.power >= 0 && cp.power <= 2)
	{
		if (!(cp.nb1 = (long double *)ft_memalloc(sizeof(long double) * cp.power)))
			exit(EXIT_FAILURE);
		if (!(cp.nb2 = (long double *)ft_memalloc(sizeof(long double) * cp.power)))
			exit(EXIT_FAILURE);
		ft_get_info(&cp);
	}
	else
		ft_printf("Wrong argument\n");
}

int		main(int ac, char **av)
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
