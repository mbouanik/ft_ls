/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_str_uni.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:22:23 by mbouanik          #+#    #+#             */
/*   Updated: 2018/01/24 15:48:23 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg_str_uni g_arg_str_uni[] = {
	{0, &ft_display_arg_c_uni_7_arg},
	{1, &ft_display_arg_c_uni_7_arg},
	{2, &ft_display_arg_c_uni_7_arg},
	{3, &ft_display_arg_c_uni_7_arg},
	{4, &ft_display_arg_c_uni_7_arg},
	{5, &ft_display_arg_c_uni_7_arg},
	{6, &ft_display_arg_c_uni_7_arg},
	{7, &ft_display_arg_c_uni_7_arg},
	{8, &ft_display_arg_c_uni_11_arg},
	{9, &ft_display_arg_c_uni_11_arg},
	{10, &ft_display_arg_c_uni_11_arg},
	{11, &ft_display_arg_c_uni_11_arg},
	{12, &ft_display_arg_c_uni_16_arg},
	{13, &ft_display_arg_c_uni_16_arg},
	{14, &ft_display_arg_c_uni_16_arg},
	{15, &ft_display_arg_c_uni_16_arg},
	{16, &ft_display_arg_c_uni_16_arg},
	{17, &ft_display_arg_c_uni_21_arg},
	{18, &ft_display_arg_c_uni_21_arg},
	{19, &ft_display_arg_c_uni_21_arg},
	{20, &ft_display_arg_c_uni_21_arg},
	{21, &ft_display_arg_c_uni_21_arg}
};

void		ft_display_arg_str_uni_c(wchar_t s)
{
	short		j;
	int			size;

	size = ft_strlen_b(s);
	if (s > 0x10FFFF || s < 0x000000 || (s >= 0xD800 && s <= 0xDFFF)
			|| (MB_CUR_MAX == 1 && s > 255))
	{
		g_p = g_ok;
		g_size = -1;
		g_keep = 0;
		return ;
	}
	if (MB_CUR_MAX == 1 && s > 127 && s <= 255)
	{
		ft_memset_g_set(g_str, s, 1);
		return ;
	}
	j = -1;
	while (g_arg_str_uni[j].c != size && ++j < 22 && g_keep)
		if (g_arg_str_uni[j].c == size)
			g_arg_str_uni[j].f(s);
}

void		ft_putstr_uni(wchar_t *s, t_type *lst)
{
	while (SIZE-- && *s && g_keep)
		ft_display_arg_str_uni_c(*s++);
}

void		ft_display_arg_str_uni_no_dash(t_type *lst, wchar_t *s)
{
	if (MFW > 0)
	{
		ft_display_mfw(lst);
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW);
		else
			ft_memset_g_set(g_str, ' ', MFW);
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
	}
	else
	{
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
	}
}

void		ft_precision(wchar_t *s, t_type *lst)
{
	int accu;
	int i;
	int j;

	i = 0;
	j = 0;
	accu = 0;
	while (s[j])
	{
		i = ft_strlen_b(s[j]);
		if (i > 0 && i <= 7 && (PMFW - 1 >= 0) && (accu += 1))
			PMFW -= 1;
		else if (i > 7 && i <= 11 && (PMFW - 2 >= 0) && (accu += 1))
			PMFW -= 2;
		else if (i > 11 && i <= 17 && (PMFW - 3 >= 0) && (accu += 1))
			PMFW -= 3;
		else if (i > 17 && i <= 21 && (PMFW - 4 >= 0) && (accu += 1))
			PMFW -= 4;
		j++;
	}
	if ((PMFW = 1) && accu < SIZE)
		SIZE = accu;
}

void		ft_display_arg_str_uni(t_type *lst, va_list list)
{
	wchar_t		*s;
	int			b;

	s = va_arg(list, wchar_t *);
	if (s == NULL && PMFW != -1)
	{
		ft_str_null(lst);
		return ;
	}
	SIZE = ft_strlen_uni(s);
	if (PMFW > 0)
		ft_precision(s, lst);
	b = ft_size_uni(s, lst);
	if (PMFW != -1)
		MFW -= b;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
	{
		if (PMFW != -1)
			ft_putstr_uni(s, lst);
		if (MFW > SIZE)
			ft_memset_g_set(g_str, ' ', MFW);
	}
	else
		ft_display_arg_str_uni_no_dash(lst, s);
}
