/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:20:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:09:45 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_octal_no_dash2(t_type *lst, long int n)
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

void		ft_display_arg_octal_no_dash(t_type *lst, long int n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_display_arg_octal_no_dash2(lst, n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_octal_no_dash2(lst, n);
}

void		ft_display_arg_octal_no_dash3(t_type *lst, long int n)
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

void		ft_display_arg_octal_dash(t_type *lst, long int n)
{
	if (FLAGS & 1 && n && --MFW)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
	{
		ft_display_arg_octal_no_dash2(lst, n);
		ft_putstr_lo(n);
	}
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_octal_no_dash2(lst, n);
		ft_putstr_lo(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
		ft_display_arg_octal_no_dash3(lst, n);
	}
	else if (MFW < SIZE && PMFW < SIZE)
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
}

void		ft_display_arg_octal(t_type *lst, va_list list)
{
	long int		n;

	n = va_arg(list, long int);
	ft_check_size_o(lst, n);
	if (FLAGS & 2)
		ft_display_arg_octal_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_octal_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_octal_no_dash2(lst, n);
		else if (MFW > SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_octal_no_dash3(lst, n);
		else if ((MFW < SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_lo(n);
	}
}
