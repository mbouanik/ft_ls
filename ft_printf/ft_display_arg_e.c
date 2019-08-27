/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 16:15:43 by mbouanik          #+#    #+#             */
/*   Updated: 2018/06/11 20:21:56 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_e_no_dash2(t_type *lst, double n)
{
	if ((FLAGS & 2) == 0)
		ft_flags_sign(lst, n);
	PMFW -= SIZE;
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_e_no_dash(t_type *lst, double n)
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
		ft_memset_g_set(g_str, '0', PMFW);
	}
	else if (PMFW >= MFW)
		ft_display_arg_e_no_dash2(lst, n);
}

void		ft_display_arg_e_no_dash3(t_type *lst, long double n)
{
	ft_flags_sign(lst, n);
	if (FLAGS & 4)
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 16 && n >= 0 && --g_p)
			ft_memset_g_set(g_str, '+', 1);
		else if (n < 0 && --g_p)
			ft_memset_g_set(g_str, '-', 1);
	}
}

void		ft_display_arg_e_dash(t_type *lst, double n)
{
	ft_flags_sign(lst, n);
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW && (MFW -= PMFW))
	{
		ft_display_arg_e_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_e(n, lst);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW < SIZE && PMFW > SIZE && PMFW >= MFW)
	{
		ft_display_arg_e_no_dash2(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_e(n, lst);
	}
	else if (MFW > SIZE && PMFW < SIZE && (MFW -= SIZE))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_e(n, lst);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_e(n, lst);
}

void		ft_display_arg_e(t_type *lst, va_list list)
{
	long double		n;

	n = (long double)va_arg(list, double);
	ft_check_size_f_e(lst, n);
	if (FLAGS & 2)
		ft_display_arg_e_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_e_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_e_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_e_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			ft_flags_sign_float(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_e(n, lst);
	}
}
