/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 20:45:11 by mbouanik          #+#    #+#             */
/*   Updated: 2018/06/11 21:10:50 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_num_up(int i, t_type *lst)
{
	if (SIZE == 0)
	{
		g_str[g_p + 1] = '1';
		while (g_str[g_p] != '.')
			g_p++;
		g_str[g_p] = '0';
		g_str[g_p + 1] = '.';
		g_p = i;
		g_str[g_p++] = '0';
	}
	else
		g_p = i;
}

void			ft_round_up_g(void)
{
	if (g_str[g_p - 1] == '0')
	{
		--g_p;
		while (g_str[g_p] == '0')
			--g_p;
		if (g_str[g_p] == '.')
			--g_p;
		g_p++;
	}
}

void			ft_round_up_f(long double n, t_type *lst)
{
	int i;

	i = g_p;
	g_p--;
	if ((uint64_t)(n * 10) % 10 >= 5)
	{
		if (g_str[g_p] <= '8' && g_str[g_p] >= '0')
			g_str[g_p] += 1;
		else if (g_str[g_p] == '9')
		{
			while ((g_str[g_p] == '9' || g_str[g_p] == '.') && SIZE)
			{
				if (g_str[g_p] == '.' && (--SIZE))
					--g_p;
				g_str[g_p] = '0';
				--g_p;
				--SIZE;
			}
			if (g_str[g_p] == '.' && (--SIZE))
				--g_p;
			if (SIZE)
				g_str[g_p] += 1;
		}
	}
	ft_num_up(i, lst);
}

void			ft_putstr_float(long double n, t_type *lst)
{
	if (n < 0)
		ft_itoustr((uint64_t)(n *= -1));
	else
		ft_itoustr((uint64_t)n);
	if (PMFW == -1)
		return ;
	ft_memset_g(g_str, '.', 1);
	n = (long double)n - (uint64_t)n;
	while (PMFW-- > 0)
	{
		n *= 10;
		ft_memset_g_set(g_str, (uint64_t)n % 10 + 48, 1);
		n = (long double)n - (uint64_t)n;
	}
	ft_round_up_f(n, lst);
	if (lst->arg_type == 'g' || lst->arg_type == 'G')
		ft_round_up_g();
}
