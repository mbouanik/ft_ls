/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:44:11 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:12:06 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_d_no_dash2(t_type *lst, int n)
{
	if ((FLAGS & 2) == 0)
		ft_flags_sign(lst, n);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_d_no_dash(t_type *lst, int n)
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
		ft_display_arg_d_no_dash2(lst, n);
}

void		ft_display_arg_d_no_dash3(t_type *lst, int n)
{
	if ((FLAGS & 4) && PMFW != -1 && (PMFW > MFW || PMFW == 0 || PMFW < 0))
	{
		if ((FLAGS & 2) == 0)
			ft_flags_sign(lst, n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		if (((FLAGS & 16 && n) || n < 0) && (FLAGS & 2) == 0)
			--MFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (((FLAGS & 16 && n) || n < 0) && (FLAGS & 2) == 0)
		{
			if (FLAGS & 16 && n >= 0)
				ft_memset_g_set(g_str, '+', 1);
			else
				ft_memset_g_set(g_str, '-', 1);
		}
	}
}

void		ft_display_arg_d_dash(t_type *lst, int n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_d_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
	{
		ft_display_arg_d_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
	}
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
		ft_display_arg_d_no_dash3(lst, n);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
}

void		ft_display_arg_d(t_type *lst, va_list list)
{
	int		n;

	if (MOD)
	{
		ft_display_arg_d_mod(lst, list);
		return ;
	}
	n = va_arg(list, int);
	ft_check_size(lst, n);
	if (FLAGS & 2)
		ft_display_arg_d_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_d_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_d_no_dash2(lst, n);
		else if (MFW > SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_d_no_dash3(lst, n);
		else if ((MFW < SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			ft_flags_sign(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itostr(n);
	}
}
