/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoustr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:14:19 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/13 16:48:03 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_itoustr_assign(uint64_t n)
{
	if (n > 0)
		ft_itoustr_assign(n / 10);
	if (n > 0)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, n % 10 + 48, 1);
	}
}

void		ft_itoustr(uint64_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_itoustr_assign(n);
}
