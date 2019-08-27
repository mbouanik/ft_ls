/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_c_uni7.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 08:59:04 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 13:11:29 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_c_uni_7_arg(wchar_t s)
{
	int			n;

	n = 0x0;
	n |= s;
	ft_memset_g(g_str, n, 1);
}

void		ft_display_arg_c_uni_7(wchar_t s, t_type *lst)
{
	ft_size(lst, 1);
	if (FLAGS & 2)
	{
		ft_display_arg_c_uni_7_arg(s);
		if (MFW > 1)
		{
			MFW -= 1;
			ft_display_mfw(lst);
			ft_memset_g_set(g_str, ' ', MFW);
		}
	}
	else
	{
		if (MFW && (MFW -= 1))
		{
			if (FLAGS & 4)
				ft_memset_g_set(g_str, '0', MFW);
			else
				ft_memset_g_set(g_str, ' ', MFW);
			ft_display_arg_c_uni_7_arg(s);
		}
		else
			ft_display_arg_c_uni_7_arg(s);
	}
}
