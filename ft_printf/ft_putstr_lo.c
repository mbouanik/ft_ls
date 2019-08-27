/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:19 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 09:53:55 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_lo_assign(uint64_t n)
{
	if (n > 0)
		ft_putstr_lo_assign(n / 8);
	if (n > 0)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, (n % 8) + 48, 1);
	}
}

void			ft_putstr_lo(uint64_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_lo_assign(n);
}
