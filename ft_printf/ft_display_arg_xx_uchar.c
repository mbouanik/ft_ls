/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arg_xx_uchar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:42:22 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/14 19:28:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_arg_xx_uchar_no_dash2(t_type *lst, unsigned char n)
{
	if ((FLAGS & 2) == 0)
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
	PMFWG = PMFW;
	PMFW -= SIZE;
	ft_display_pmfw(lst);
	ft_memset_g_set(g_str, '0', PMFW);
	ft_putstr_x(n);
}

void	ft_display_arg_xx_uchar_dash(t_type *lst, unsigned char n)
{
	if (FLAGS & 1 && n)
		ft_memcpy_g(g_str, "0X", 2);
	if (PMFW > SIZE && (PMFW > MFW || PMFW == MFW))
		ft_display_arg_xx_uchar_no_dash2(lst, n);
	else if (MFW > SIZE && PMFW > SIZE && PMFW < MFW)
	{
		ft_display_arg_xx_uchar_no_dash2(lst, n);
		ft_putstr_x(n);
		MFW -= PMFWG;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else if (MFW > SIZE && (PMFW < SIZE || PMFW == 0))
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
		MFW -= SIZE;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
	}
	else
	{
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
	}
}

void	ft_display_arg_xx_uchar_no_dash(t_type *lst, unsigned char n)
{
	if (MFW > PMFW)
	{
		MFW -= PMFW;
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
		if (FLAGS & 4)
		{
			PMFW -= SIZE;
			ft_display_pmfw(lst);
			ft_memset_g_set(g_str, '0', PMFW);
		}
		ft_putstr_x(n);
	}
	else
		ft_display_arg_xx_uchar_no_dash2(lst, n);
}

void	ft_display_arg_xx_uchar_no_dash3(t_type *lst, unsigned char n)
{
	MFW -= SIZE;
	if (FLAGS & 4 && PMFW != -1)
	{
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, '0', MFW);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
	}
	else
	{
		ft_display_mfw(lst);
		ft_memset_g_set(g_str, ' ', MFW);
		if (FLAGS & 1 && n)
			ft_memcpy_g(g_str, "0X", 2);
		if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
			ft_putstr_x(n);
	}
}

void	ft_display_arg_xx_uchar(t_type *lst, va_list list)
{
	unsigned char	n;

	n = (unsigned char)va_arg(list, unsigned int);
	SIZE = ft_strlen_hexa((unsigned char)n);
	ft_size(lst, SIZE);
	if (FLAGS & 1 && MFW >= 2)
		MFW -= 2;
	if (FLAGS & 2)
		ft_display_arg_xx_uchar_dash(lst, n);
	else
	{
		if (MFW > SIZE && PMFW > SIZE)
			ft_display_arg_xx_uchar_no_dash(lst, n);
		else if (((MFW <= SIZE || MFW == 0) && PMFW >= SIZE))
			ft_display_arg_xx_uchar_no_dash2(lst, n);
		else if (MFW >= SIZE && (PMFW <= SIZE || PMFW == 0))
			ft_display_arg_xx_uchar_no_dash3(lst, n);
		else if ((MFW <= SIZE || MFW == 0) && (PMFW <= SIZE || PMFW == 0))
		{
			if (FLAGS & 1 && n)
				ft_memcpy_g(g_str, "0X", 2);
			if ((PMFW == -1 && n) || (PMFW != -1 && !(n)) || (PMFW != -1 && n))
				ft_putstr_x(n);
		}
	}
}
