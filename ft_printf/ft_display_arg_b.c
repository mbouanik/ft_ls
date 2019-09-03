/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:21:46 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 11:27:46 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_mfw(t_type *lst)
{
	ft_display_mfw(lst);
	ft_memset_g_set(g_str, ' ', MFW);
}

void		ft_display_arg_b_dash(t_type *lst, long long n)
{
	if (PMFW > SIZE && PMFW >= SIZE)
	{
		PMFWG = PMFW;
		PMFW -= SIZE;
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFW);
	}
	ft_putstr_b(n);
	if (MFW > SIZE && PMFW > SIZE)
	{
		MFW -= PMFWG;
		ft_mfw(lst);
	}
	else
	{
		MFW -= SIZE;
		ft_mfw(lst);
	}
}

void		ft_display_arg_b(t_type *lst, va_list list)
{
	long long	n;

	n = va_arg(list, long long);
	SIZE = ft_strlen_b(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_b_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
		{
			if (PMFW > SIZE && (MFW -= PMFW))
				ft_mfw(lst);
			else if (PMFW < SIZE && (MFW -= SIZE))
				ft_mfw(lst);
			PMFW -= SIZE;
			ft_display_pmfw(lst);
			ft_memset_g_set(g_str, '0', PMFW);
		}
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_memset_g_set(g_str, '0', PMFW - SIZE);
		else if (MFW >= SIZE && (PMFW == 0 || MFW <= SIZE))
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
		ft_putstr_b(n);
	}
}
