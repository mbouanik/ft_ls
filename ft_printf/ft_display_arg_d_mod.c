/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_mod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:14:14 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/16 13:10:22 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg_d[] = {
	{104, &ft_display_arg_d_short},
	{208, &ft_display_arg_d_schar},
	{108, &ft_display_arg_d_intm},
	{216, &ft_display_arg_d_intm},
	{106, &ft_display_arg_d_intm},
	{122, &ft_display_arg_d_intm},
	{0, NULL}
};

void		ft_display_arg_d_mod(t_type *lst, va_list list)
{
	int j;

	j = 0;
	while (MOD != g_arg_d[j].c && g_arg_d[j].c)
		++j;
	g_arg_d[j].f(lst, list);
}
