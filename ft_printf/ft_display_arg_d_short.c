/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_short.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:18:08 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 13:21:21 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_d_short_no_dash2(t_type *lst, short n)
{
	if ((FLAGS & 2) == 0)
		ft_flags_sign(lst, n);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	ft_itostr(n);
}

void		ft_display_arg_d_short_dash(t_type *lst, short n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_d_short_no_dash2(lst, n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
		ft_display_arg_d_short_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
}

void		ft_display_arg_d_short_no_dash(t_type *lst, short n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n > 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
		PMFW -= SIZE;
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFW);
		ft_itostr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_d_short_no_dash2(lst, n);
}

void		ft_display_arg_d_short_no_dash3(t_type *lst, short n)
{
	if ((FLAGS & 4) && PMFW != -1 && (PMFW > MFW || PMFW == 0))
	{
		ft_flags_sign(lst, n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 16 && n > 0)
			ft_memset_g_set(g_str, '+', 1);
		if (n < 0)
			ft_memset_g_set(g_str, '-', 1);
	}
	ft_itostr(n);
}

void		ft_display_arg_d_short(t_type *lst, va_list list)
{
	short	n;

	n = (short)va_arg(list, int);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_d_short_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_d_short_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_d_short_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_d_short_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
				ft_flags_sign(lst, n);
			ft_itostr(n);
		}
		else if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
	}
}
