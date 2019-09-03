/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 07:59:51 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:09:28 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_o_no_dash2(t_type *lst, unsigned int n)
{
	if ((FLAGS & 2) == 0)
		if ((FLAGS & 1 && n) || (FLAGS & 1 && PMFW == -1 && !(n)))
		{
			if (PMFW > SIZE)
				--PMFW;
			ft_memset_g_set(g_str, '0', 1);
		}
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_o_no_dash(t_type *lst, unsigned int n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	ft_display_arg_o_no_dash2(lst, n);
}

void		ft_display_arg_o_no_dash3(t_type *lst, unsigned int n)
{
	MFW -= SIZE;
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1)
		ft_memset_g_set(g_str, '0', MFW);
	else
		ft_memset_g_set(g_str, ' ', MFW);
	if (FLAGS & 1 && n && ((FLAGS & 2) == 0) && g_p--)
		ft_memset_g_set(g_str, '0', 1);
}

void		ft_display_arg_o_dash(t_type *lst, unsigned int n)
{
	if ((FLAGS & 1 && n && --MFW) || (FLAGS & 1 && PMFW == -1 && !(n)))
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
	{
		ft_display_arg_o_no_dash2(lst, n);
		ft_putstr_octal(n);
	}
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_o_no_dash2(lst, n);
		ft_putstr_octal(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW >= SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
		ft_display_arg_o_no_dash3(lst, n);
	}
	else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_octal(n);
}

void		ft_display_arg_o(t_type *lst, va_list list)
{
	unsigned int		n;

	if (MOD)
	{
		ft_display_arg_o_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	ft_check_size_o(lst, n);
	if (FLAGS & 2)
		ft_display_arg_o_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_o_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_o_no_dash2(lst, n);
		else if (MFW > SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_o_no_dash3(lst, n);
		else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
	}
}
