/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:14:24 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 09:54:12 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_hexa_assign(uintmax_t n)
{
	if (n)
		ft_putstr_hexa_assign(n / 16);
	if (n && (n % 16) <= 9)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, (n % 16) + 48, 1);
	}
	if ((n % 16) > 9)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, (n % 16) + 87, 1);
	}
}

void			ft_putstr_hexa(uintmax_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_hexa_assign(n);
}
