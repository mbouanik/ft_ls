/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d_intm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:45:29 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/05 17:21:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_d_intm_no_dash2(t_type *lst, long n)
{
	if ((FLAGS & 2) == 0)
		ft_flags_sign(lst, n);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	ft_longtoa(n);
}

void	ft_display_arg_d_intm_dash(t_type *lst, long n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_d_intm_no_dash2(lst, n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
		ft_display_arg_d_intm_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_longtoa(n);
}

void	ft_display_arg_d_intm_no_dash(t_type *lst, long n)
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
		ft_longtoa(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_d_intm_no_dash2(lst, n);
}

void	ft_display_arg_d_intm_no_dash3(t_type *lst, long n)
{
	if (FLAGS & 4 && PMFW != -1 && PMFW > SIZE)
	{
		ft_flags_sign(lst, n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		if (FLAGS & 16)
			--MFW;
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 16)
			ft_memset_g_set(g_str, '+', 1);
	}
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_longtoa(n);
}

void	ft_display_arg_d_intm(t_type *lst, va_list list)
{
	long		n;

	n = va_arg(list, long);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_d_intm_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_d_intm_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_d_intm_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_d_intm_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if ((FLAGS & 16 || FLAGS & 8) || n < 0)
				ft_flags_sign(lst, n);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_longtoa(n);
		}
	}
}
