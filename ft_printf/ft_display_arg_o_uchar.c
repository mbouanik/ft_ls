/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_o_uchar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:20:51 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/14 19:18:15 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_o_uchar_no_dash2(t_type *lst, unsigned char n)
{
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_uchar_dash(t_type *lst, unsigned char n)
{
	if (FLAGS & 1 && n && --MFW)
		ft_memset_g_set(g_str, '0', 1);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
		ft_display_arg_o_uchar_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_o_uchar_no_dash2(lst, n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
			ft_putstr_octal(n);
}

void	ft_display_arg_o_uchar_no_dash(t_type *lst, unsigned char n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_display_arg_o_uchar_no_dash2(lst, n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_o_uchar_no_dash2(lst, n);
}

void	ft_display_arg_o_uchar_no_dash3(t_type *lst, unsigned char n)
{
	MFW -= SIZE;
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1)
		ft_memset_g_set(g_str, '0', MFW);
	else
		ft_memset_g_set(g_str, ' ', MFW);
	if (FLAGS & 1 && g_p--)
		ft_memset_g_set(g_str, '0', 1);
	ft_putstr_octal(n);
}

void	ft_display_arg_o_uchar(t_type *lst, va_list list)
{
	unsigned char		n;

	n = (unsigned char)va_arg(list, int);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_o_uchar_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_o_uchar_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_o_uchar_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_o_uchar_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memset_g_set(g_str, '0', 1);
			if ((PMFW == -1 && (FLAGS & 1 || n)) || (PMFW != -1 && (!(n) || n)))
				ft_putstr_octal(n);
		}
	}
}
