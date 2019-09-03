/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:19:41 by mbouanik          #+#    #+#             */
/*   Updated: 2017/09/19 20:40:32 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_str_null_no_dash(t_type *lst)
{
	if (MFW > SIZE)
	{
		if (FLAGS & 4)
			ft_memset_g_set(g_str, '0', MFW - SIZE);
		else
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", SIZE);
	}
	else
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", SIZE);
	}
}

void		ft_str_null(t_type *lst)
{
	if ((SIZE = 6) && PMFW < SIZE && PMFW > 0)
		SIZE = PMFW;
	if (PMFW == -1)
		SIZE = 0;
	ft_size(lst, SIZE);
	if (FLAGS & 2)
	{
		if (PMFW != -1)
			ft_memcpy_g(g_str, "(null)", SIZE);
		if (MFW > 0 && MFW > SIZE)
			ft_memset_g_set(g_str, ' ', MFW - SIZE);
	}
	else
		ft_str_null_no_dash(lst);
}
