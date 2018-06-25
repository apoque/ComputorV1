/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:36 by apoque            #+#    #+#             */
/*   Updated: 2018/06/15 17:48:40 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H
# include "../libft/include/libft.h"

typedef struct				s_comp
{
		long double			*nb[2];
		int					power;
		int					new_power;
		char				*str;
}							t_comp;

typedef struct				s_info
{
		int					i;
		long double			nb;
		int					power;
		short				eq;
		short				neg;
}							t_info;

long double	ft_negpower(int i);
void		ft_iseq(char *str, int *i, short *eq);
void		ft_isneg(char *str, int *i, short *neg);
void		ft_solve(t_comp *cp);
void		ft_second_degree(t_comp *cp);
long double	ft_float_square(long double nb);
void		ft_printfloat(long double nb);
#endif
