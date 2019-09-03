/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:19:40 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/31 17:08:02 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_u_no_dash2(t_type *lst)
{
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
}

void		ft_display_arg_u_no_dash(t_type *lst)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		ft_display_arg_u_no_dash2(lst);
	}
	else if (PMFW >= MFW)
		ft_display_arg_u_no_dash2(lst);
}

void		ft_display_arg_u_no_dash3(t_type *lst)
{
	MFW -= SIZE;
	ft_display_mfw(lst);
	if (FLAGS & 4 && PMFW != -1 && (PMFW >= MFW || PMFW == 0))
		ft_memset_g_set(g_str, '0', MFW);
	else
		ft_memset_g_set(g_str, ' ', MFW);
}

void		ft_display_arg_u_dash(t_type *lst, unsigned int n)
{
	if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_u_no_dash2(lst);
		ft_itoustr(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if ((MFW < SIZE && PMFW > SIZE) || PMFW > MFW || PMFW == MFW)
	{
		if (PMFW > SIZE)
			ft_display_arg_u_no_dash2(lst);
		ft_itoustr(n);
	}
	else if (MFW > SIZE && PMFW < SIZE)
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
		ft_display_arg_u_no_dash3(lst);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
}

void		ft_display_arg_u(t_type *lst, va_list list)
{
	unsigned int	n;

	if (MOD)
	{
		ft_display_arg_u_mod(lst, list);
		return ;
	}
	n = va_arg(list, unsigned int);
	SIZE = ft_strlen_num(n);
	if (PMFW == -1)
		SIZE = 0;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
		ft_display_arg_u_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_u_no_dash(lst);
		else if ((MFW <= SIZE || MFW == 0) && PMFW >= SIZE)
			ft_display_arg_u_no_dash2(lst);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_u_no_dash3(lst);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_itoustr(n);
	}
}
