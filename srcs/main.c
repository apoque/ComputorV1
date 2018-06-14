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

int		ft_get_power(char *str)
{
	int	power;
	int	i;

	i = 0;
	power = -1;
	ft_printf("str = [%s]\n", str);
	while (str[i] != '\0')
	{
		while (str[i] != 'X' && str[i] != '\0')
			i++;
		ft_printf("I = %i et power %i\n", i, power);
		if (str[i] == 'X' && str[i + 1] == '^')
		{
			if (power < ft_atoi(&str[i + 1]))
				power = ft_atoi(&str[i + 1]);
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
	t_comp	cp1;

	ft_bzero(&cp1, sizeof(t_comp));
	cp1.str = str;
	cp1.power = ft_get_power(str);
	ft_printf("power = %i\n", cp1.power);
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
