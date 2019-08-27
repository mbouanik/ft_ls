/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_dd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 06:16:13 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 13:40:39 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_dd_no_dash2(t_type *lst, long n)
{
	if ((FLAGS & 2) == 0)
		if (n < 0 || FLAGS & 16 || FLAGS & 8)
		{
			if ((FLAGS & 16) && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			else if (n < 0)
				ft_memset_g_set(g_str, '-', 1);
			else if (FLAGS & 8 && n > 0)
				ft_memset_g_set(g_str, ' ', 1);
		}
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_dd_no_dash(t_type *lst, long n)
{
	if (MFW > PMFW)
	{
		if (n < 0 || FLAGS & 16)
			MFW--;
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (n < 0 || FLAGS & 16)
		{
			if (FLAGS & 16 && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
		PMFW -= SIZE;
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFW);
	}
	else if (PMFW >= MFW)
		ft_display_arg_dd_no_dash2(lst, n);
}

void		ft_display_arg_dd_no_dash3(t_type *lst, long n)
{
	MFW -= SIZE;
	if (FLAGS & 4 && PMFW != -1)
	{
		if ((FLAGS & 2) == 0)
			ft_flags_sign(lst, n);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		if (((FLAGS & 16 && n) || n < 0) && (FLAGS & 2) == 0)
			--MFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (((FLAGS & 16 && n) || n < 0) && (FLAGS & 2) == 0)
		{
			if (FLAGS & 16 && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			if (n < 0)
				ft_memset_g_set(g_str, '-', 1);
		}
	}
}

void		ft_display_arg_dd_dash(t_type *lst, long n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_dd_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
	{
		ft_display_arg_dd_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
	}
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
		ft_display_arg_dd_no_dash3(lst, n);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
}

void		ft_display_arg_dd(t_type *lst, va_list list)
{
	long	n;

	n = va_arg(list, long);
	if ((SIZE = ft_strlen_num(n)) && PMFW == -1 && n == 0)
		SIZE = 1;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_dd_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_dd_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_dd_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_dd_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
				ft_flags_sign(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
	}
}
