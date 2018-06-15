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
		long double			nb1[3];
		long double			nb2[3];
		int					power;
		char				*str;
}							t_comp;

#endif
