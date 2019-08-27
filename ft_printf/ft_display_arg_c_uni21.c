/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_c_uni21.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 08:46:20 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 13:13:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_c_uni_21_arg(wchar_t s)
{
	wchar_t		index;
	int			n;
	int			p;

	n = 0xF0;
	p = 0x80;
	index = s;
	s >>= 18;
	n |= s;
	ft_memset_g(g_str, n, 1);
	s = index;
	s = (s & 0x3F000) >> 12;
	p |= s;
	ft_memset_g(g_str, p, 1);
	s = index;
	p = 0x80;
	s = (s & 0xFC0) >> 6;
	p |= s;
	ft_memset_g(g_str, p, 1);
	s = index;
	p = 0x80;
	s &= 0x3F;
	p |= s;
	ft_memset_g(g_str, p, 1);
}

void		ft_display_arg_c_uni_21(wchar_t s, t_type *lst)
{
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_display_arg_c_uni_21_arg(s);
		if (MFW > 4)
		{
			MFW -= 4;
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW);
		}
	}
	else
	{
		if (MFW > 4 && (MFW -= 4))
		{
			ft_display_mfw(lst);
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW);
			else
				ft_memset_g_set(g_str, ' ', MFW);
			ft_display_arg_c_uni_21_arg(s);
		}
		else
			ft_display_arg_c_uni_21_arg(s);
	}
}
