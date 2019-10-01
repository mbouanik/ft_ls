/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:57:29 by mbouanik          #+#    #+#             */
/*   Updated: 2018/06/12 14:45:37 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_arg_g_dash(t_type *lst, long double n)
{
	// ft_flags_sign_float(lst, n);
	if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
		ft_putstr_float_g(n, lst);
	if ((FLAGS & 1) && PMFWG)
	{
		PMFWG -= SIZE;
		ft_display_pmfw(lst);
		ft_memset_g_set(g_str, '0', PMFWG + 1);
	}
	else if (MFW > SIZE)
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
}

void		ft_display_arg_g_no_dash(t_type *lst, long double n)
{
	if (n < 0 || FLAGS & 16)
		MFW--;
	if (FLAGS & 4)
	{
		// ft_flags_sign_float(lst, n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
	}
	else
	{
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (n < 0 || FLAGS & 16)
			ft_flags_sign_float(lst, n);
	}
}

void		ft_display_arg_g(t_type *lst, va_list list)
{
	long double		n;

	n = (long double)va_arg(list, double);
	ft_check_size_g(lst, n);
	if (FLAGS & 2 || (FLAGS & 1 && PMFWG))
		ft_display_arg_g_dash(lst, n);
	else
	{
		if (MFW > SIZE)
			ft_display_arg_g_no_dash(lst, n);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_float_g(n, lst);
	}
}
