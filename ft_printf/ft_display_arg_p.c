/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:34:11 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:11:05 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_p_no_dash2(t_type *lst, uint64_t n)
{
	ft_memcpy_g(g_str, "0x", 2);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_putstr_hexa(n);
}

void	ft_display_p_dash(t_type *lst, uint64_t n)
{
	MFW -= 2;
	ft_memcpy_g(g_str, "0x", 2);
	if (PMFW >= SIZE && (PMFW >= MFW || PMFW == MFW))
		ft_display_p_no_dash2(lst, n);
	else if (MFW >= SIZE && PMFW >= SIZE && PMFW < MFW)
	{
		ft_display_p_no_dash2(lst, n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_hexa(n);
}

void	ft_display_p_no_dash(t_type *lst, uint64_t n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_display_p_no_dash2(lst, n);
	}
	else
		ft_display_p_no_dash2(lst, n);
}

void	ft_display_p_no_dash3(t_type *lst, uint64_t n)
{
	if (FLAGS & 4 && PMFW == 0)
	{
		ft_memcpy_g(g_str, "0x", 2);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_memcpy_g(g_str, "0x", 2);
	}
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_putstr_hexa(n);
}

void	ft_display_arg_p(t_type *lst, va_list list)
{
	uint64_t	n;

	n = va_arg(list, uint64_t);
	SIZE = ft_strlen_hexa(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_p_dash(lst, n);
	else
	{
		if (MFW >= SIZE && PMFW >= SIZE && (MFW -= 2))
			ft_display_p_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_p_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0) && (MFW -= 2))
			ft_display_p_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			ft_memcpy_g(g_str, "0x", 2);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_putstr_hexa(n);
		}
	}
}
