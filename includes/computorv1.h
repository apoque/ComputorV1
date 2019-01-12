/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:48:36 by apoque            #+#    #+#             */
/*   Updated: 2019/01/12 16:16:23 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H
# include "../libft/includes/printf.h"

typedef struct				s_comp
{
	float				*nb[2];
	int					power;
	int					new_power;
	char				*str;
}							t_comp;

typedef struct				s_info
{
	int					i;
	int					nb_on;
	int					power_on;
	float				nb;
	int					power;
	short				eq;
	short				neg;
}							t_info;

float						ft_negpower(int i);
float						ft_db(char *str, int i);
void						ft_get_power_bis(t_comp *cp, t_info *info);
void						ft_get_factor(t_comp *cp, t_info *info);
void						ft_iseq(char *str, int *i, short *eq);
void						ft_isneg(char *str, int *i, short *neg);
void						ft_solve(t_comp *cp, int detail);
void						ft_second_degree(t_comp *cp);
float						ft_float_square(float nb);
void						ft_printfloat(float nb);
void						ft_display_detail(t_comp *cp, int i);
#endif
