/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:19:16 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 09:53:07 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putstr_octal_assign(unsigned int n)
{
	if (n > 0)
		ft_putstr_octal_assign(n / 8);
	if (n > 0)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, (n % 8) + 48, 1);
	}
}

void			ft_putstr_octal(unsigned int n)
{
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	ft_putstr_octal_assign(n);
}
