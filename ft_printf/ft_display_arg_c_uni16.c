/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_c_uni16.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:27:50 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 13:09:29 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_c_uni_16_arg(wchar_t s)
{
	wchar_t		index;
	int			n;
	int			p;

	n = 0xE0;
	p = 0x80;
	index = s;
	s >>= 12;
	n |= s;
	ft_memset_g(g_str, n, 1);
	s = index;
	s = (s & 0XFC0) >> 6;
	p |= s;
	ft_memset_g(g_str, p, 1);
	s = index;
	p = 0x80;
	s &= 0x3F;
	p |= s;
	ft_memset_g(g_str, p, 1);
}

void		ft_display_arg_c_uni_16(wchar_t s, t_type *lst)
{
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_display_arg_c_uni_16_arg(s);
		if (MFW > 3)
		{
			MFW -= 3;
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW);
		}
	}
	else
	{
		if (MFW > 3 && (MFW -= 3))
		{
			ft_display_mfw(lst);
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW);
			else
				ft_memset_g_set(g_str, ' ', MFW);
			ft_display_arg_c_uni_16_arg(s);
		}
		else
			ft_display_arg_c_uni_16_arg(s);
	}
}
