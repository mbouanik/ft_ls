/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:44:20 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 16:46:47 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_s_no_dash(t_type *lst, char *s)
{
	if (MFW > SIZE)
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW);
		else
			ft_memset_g_set(g_str, ' ', MFW);
		if (PMFW != -1 && ((FLAGS & 2) == 0))
			ft_memcpy_g(g_str, s, SIZE);
	}
	else
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, s, SIZE);
	}
}

void		ft_display_arg_s(t_type *lst, va_list list)
{
	char	*s;

	if (MOD == 'l')
	{
		ft_display_arg_str_uni(lst, list);
		return ;
	}
	s = va_arg(list, char *);
	if (s == NULL && PMFW != -1)
	{
		ft_str_null(lst);
		return ;
	}
	ft_check_size_str(lst, s);
	if (FLAGS & 2)
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, s, SIZE);
		if (MFW > 0 && (PMFW = -1))
			ft_display_arg_s_no_dash(lst, s);
	}
	else
		ft_display_arg_s_no_dash(lst, s);
}

void		ft_display_arg_c_no_dash(t_type *lst, int s)
{
	if (MFW > 1)
	{
		ft_display_mfw(lst);
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW - 1);
		else
			ft_memset_g_set(g_str, ' ', MFW - 1);
		ft_memset_g_set(g_str, s, 1);
	}
	else
		ft_memset_g_set(g_str, s, 1);
}

void		ft_display_arg_c(t_type *lst, va_list list)
{
	int		s;

	if (MOD)
	{
		ft_display_arg_c_uni(lst, list);
		return ;
	}
	s = va_arg(list, int);
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_memset_g_set(g_str, s, 1);
		ft_display_mfw(lst);
		if (MFW > 1)
			ft_memset_g_set(g_str, ' ', MFW - 1);
	}
	else
		ft_display_arg_c_no_dash(lst, s);
}

void		ft_display_no_arg(t_type *lst)
{
	if ((SIZE = 1) && !(lst->arg_type))
		SIZE = 0;
	ft_size_s();
	if (FLAGS & 2)
	{
		ft_memset_g_set(g_str, lst->arg_type, SIZE);
		if (MFW > 1 && (MFW -= SIZE))
		{
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW);
		}
	}
	else
	{
		if (MFW > SIZE && (MFW -= SIZE))
		{
			ft_display_mfw(lst);
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW);
			else
				ft_memset_g_set(g_str, ' ', MFW);
		}
		ft_memset_g_set(g_str, lst->arg_type, SIZE);
	}
	g_ok = g_p;
}
