/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_uu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:03:57 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/14 19:19:40 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_uu_no_dash2(t_type *lst, unsigned long n)
{
	if ((FLAGS & 2) == 0)
		if (FLAGS & 8 && PMFW++ && SIZE++)
			ft_memset_g_set(g_str, ' ', 1);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	ft_itoustr(n);
}

void		ft_display_arg_uu_dash(t_type *lst, unsigned long n)
{
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_uu_no_dash2(lst, n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW < SIZE && PMFW > SIZE) || PMFW > MFW || PMFW == MFW)
		ft_display_arg_uu_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
}

void		ft_display_arg_uu_no_dash(t_type *lst, unsigned long n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		PMFW -= SIZE;
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFW);
		ft_itoustr(n);
	}
	else if (PMFW >= MFW)
		ft_display_arg_uu_no_dash2(lst, n);
}

void		ft_display_arg_uu_no_dash3(t_type *lst, unsigned long n)
{
	MFW -= SIZE;
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 8 && SIZE++)
			ft_memset_g_set(g_str, ' ', 1);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
		ft_memset_g_set(g_str, ' ', MFW);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_itoustr(n);
}

void		ft_display_arg_uu(t_type *lst, va_list list)
{
	unsigned long	n;

	n = va_arg(list, unsigned long);
	SIZE = ft_strlen_num(n);
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_uu_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_uu_no_dash(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_uu_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_uu_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 8)
				ft_memset_g_set(g_str, ' ', 1);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_itoustr(n);
		}
	}
}
