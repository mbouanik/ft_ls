/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:33:25 by mbouanik          #+#    #+#             */
/*   Updated: 2018/06/11 21:22:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_round_up(double n)
{
	int i;

	i = g_p;
	g_p--;
	if ((uint64_t)(n * 10) % 10 >= 5)
	{
		if (g_str[g_p] <= '8')
			g_str[g_p] += 1;
		else if (g_str[g_p] == '9')
		{
			while (g_str[g_p] == '9')
			{
				g_str[g_p] = '0';
				g_p--;
			}
			if (g_str[g_p] == '.')
				--g_p;
			g_str[g_p] += 1;
		}
	}
	g_p = i;
}

void			ft_putstr_float_g(long double n, t_type *lst)
{
	int i;

	i = ft_strlen_num((uint64_t)n);
	if (g_ok == 1)
		ft_putstr_float(n, lst);
	else
	{
		if (PMFW != -1 || PMFW > 0)
			PMFW -= 1;
		ft_putstr_float_e(n, lst);
	}
}
