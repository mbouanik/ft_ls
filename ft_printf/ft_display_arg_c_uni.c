/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_c_uni.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:45:55 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 16:30:09 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg_uni g_arg_c_uni[] = {
	{0, &ft_display_arg_c_uni_7},
	{1, &ft_display_arg_c_uni_7},
	{2, &ft_display_arg_c_uni_7},
	{3, &ft_display_arg_c_uni_7},
	{4, &ft_display_arg_c_uni_7},
	{5, &ft_display_arg_c_uni_7},
	{6, &ft_display_arg_c_uni_7},
	{7, &ft_display_arg_c_uni_7},
	{8, &ft_display_arg_c_uni_11},
	{9, &ft_display_arg_c_uni_11},
	{10, &ft_display_arg_c_uni_11},
	{11, &ft_display_arg_c_uni_11},
	{12, &ft_display_arg_c_uni_16},
	{13, &ft_display_arg_c_uni_16},
	{14, &ft_display_arg_c_uni_16},
	{15, &ft_display_arg_c_uni_16},
	{16, &ft_display_arg_c_uni_16},
	{17, &ft_display_arg_c_uni_21},
	{18, &ft_display_arg_c_uni_21},
	{19, &ft_display_arg_c_uni_21},
	{20, &ft_display_arg_c_uni_21},
	{21, &ft_display_arg_c_uni_21}
};

void		ft_display_no_arg_c_uni(t_type *lst)
{
	ft_size(lst, 1);
	SIZE = 1;
	if (FLAGS & 2)
	{
		if (MFW > 1)
		{
			MFW -= SIZE;
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW);
		}
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		if (MFW > SIZE)
		{
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW);
			else
				ft_memset_g_set(g_str, ' ', MFW);
		}
	}
}

void		ft_display_arg_c_uni(t_type *lst, va_list list)
{
	short		j;
	wchar_t		s;

	s = va_arg(list, wchar_t);
	if (s > 0x10FFFF || s < 0x000000 || (s >= 0xD800 && s <= 0xDFFF)
			|| (MB_CUR_MAX == 1 && s > 255))
	{
		g_p = g_ok;
		g_size = -1;
		g_keep = 0;
		return ;
	}
	SIZE = ft_strlen_b(s);
	if (MB_CUR_MAX == 1 && s > 127 && s <= 255)
	{
		ft_memset_g_set(g_str, s, 1);
		ft_display_no_arg_c_uni(lst);
		g_ok = g_p;
		return ;
	}
	j = -1;
	while (g_arg_c_uni[j].c != SIZE && ++j < 22)
		if (g_arg_c_uni[j].c == SIZE)
			g_arg_c_uni[j].f(s, lst);
	g_ok = g_p;
}
