/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:25:30 by mbouanik          #+#    #+#             */
/*   Updated: 2017/03/29 13:28:31 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_b_assign(uintmax_t n)
{
	if (n > 0)
		ft_putstr_b_assign(n / 2);
	if (n > 0)
		g_str[g_p++] = (n % 2) + 48;
}

void			ft_putstr_b(uintmax_t n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_b_assign(n);
}
