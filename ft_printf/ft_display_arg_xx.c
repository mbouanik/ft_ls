/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_xx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:05:13 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:10:34 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_xx_no_dash2(t_type *lst, unsigned int n)
{
	if ((FLAGS & 2) == 0)
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_xx_no_dash(t_type *lst, unsigned int n)
{
	if (MFW > PMFW)
	{
		if (FLAGS & 1)
			MFW -= 2;
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_display_arg_xx_no_dash2(lst, n);
	}
	else
		ft_display_arg_xx_no_dash2(lst, n);
}

void		ft_display_arg_xx_no_dash3(t_type *lst, unsigned int n)
{
	if (FLAGS & 1 && n && ((FLAGS & 2) == 0))
		MFW -= 2;
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 1 && n && ((FLAGS & 2) == 0))
			ft_memcpy_g(g_str, "0X", 2);
	}
}

void		ft_display_arg_xx_dash(t_type *lst, unsigned int n)
{
	if (FLAGS & 1 && n && (MFW -= 2))
		ft_memcpy_g(g_str, "0X", 2);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
	{
		ft_display_arg_xx_no_dash2(lst, n);
		ft_putstr_x(n);
	}
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_xx_no_dash2(lst, n);
		ft_putstr_x(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
		ft_display_arg_xx_no_dash3(lst, n);
	}
	else if ((MFW < SIZE || MFW == 0) && (PMFW < SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
}

void		ft_display_arg_xx(t_type *lst, va_list list)
{
	unsigned int	n;

	if (MOD)
	{
		ft_display_arg_xx_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	ft_check_size_hexa(lst, n);
	if (FLAGS & 2)
		ft_display_arg_xx_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_xx_no_dash(lst, n);
		else if (((MFW <= SIZE || MFW == 0) && PMFW >= SIZE))
			ft_display_arg_xx_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_xx_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0X", 2);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
	}
}
