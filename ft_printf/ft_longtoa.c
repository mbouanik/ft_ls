/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 06:24:05 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/13 16:49:02 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_num;

static void		ft_assign_num(long n)
{
	if (n > 0)
		ft_assign_num(n / 10);
	if (n > 0)
	{
		if (n % 10 == 0)
			g_num += 1;
		else
			g_num = 0;
		if (g_p + 1 > BUFF_SIZE)
			ft_size_s();
		ft_memset_g_set(g_str, n % 10 + 48, 1);
	}
}

static void		ft_sign(long *n, int *s)
{
	if (*n < 0)
	{
		*s = 1;
		*n *= -1;
	}
}

void			ft_longtoa(long n)
{
	int		neg;

	g_num = 0;
	if (n < -9223372036854775807)
	{
		ft_memcpy_g(g_str, "9223372036854775808", 19);
		return ;
	}
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	neg = 0;
	ft_sign(&n, &neg);
	neg = 0;
	ft_assign_num(n);
}

void			ft_longtoa_g(long n)
{
	int		neg;

	g_num = 0;
	if (n < -9223372036854775807)
	{
		ft_memcpy_g(g_str, "9223372036854775808", 19);
		return ;
	}
	if (n == 0)
	{
		g_str[g_p++] = n + 48;
		return ;
	}
	neg = 0;
	ft_sign(&n, &neg);
	neg = 0;
	ft_assign_num(n);
	g_p = g_p - g_num;
}
