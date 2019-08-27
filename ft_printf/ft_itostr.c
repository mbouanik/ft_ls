/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:21:06 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/13 16:46:22 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_assign_num(int n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
	{
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, n % 10 + '0', 1);
	}
}

static void		ft_sign(int *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

void			ft_itostr(int n)
{
	int		neg;

	if (n == -2147483648)
	{
		ft_memcpy_g(g_str, "2147483648", 10);
		return ;
	}
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	neg = 0;
	ft_sign(&n, &neg);
	ft_assign_num(n);
}
