/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:35:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/03 05:34:16 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_size_f(t_type *lst, uint64_t n)
{
	SIZE = ft_strlen_num((uint64_t)n);
	if (PMFW == 0 && (PMFW = 6))
		SIZE += 7;
	else if (PMFW > 0)
		SIZE += PMFW + 1;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
	ft_size(lst, SIZE);
}

void		ft_check_size_f_g(t_type *lst, double n)
{
	SIZE = ft_strlen_num((uint64_t)n);
	PMFW = ft_strlen_comma(n - (uint64_t)n);
	if (SIZE + PMFW > 10 || (PMFWG > SIZE && PMFW > SIZE))
	{
		if (PMFWG > SIZE)
		{
			PMFW = PMFWG - SIZE;
			SIZE += PMFW + 1;
		}
		else if (PMFWG == SIZE)
			PMFW = -1;
		else
		{
			PMFW = 16 - SIZE + 1;
			SIZE = 17 + 1;
		}
	}
	else if (PMFWG == 0)
	{
		PMFW = 6 - SIZE;
		SIZE = 7;
	}
	else
		SIZE += PMFW + 1;
	ft_size(lst, SIZE);
}

void		ft_check_size_f_e(t_type *lst, long double n)
{
	SIZE = 6;
	if (PMFW == 1)
		SIZE += 4;
	else if (PMFW == 0 && (PMFW = 6))
		SIZE += 6;
	else if (PMFW > 0)
		SIZE += PMFW;
	if (PMFW == -1 && n == 0)
		SIZE = 0;
}

void		ft_check_size_str(t_type *lst, char *s)
{
	SIZE = ft_strlen(s);
	if ( SIZE > PMFW && PMFW > 0)
		SIZE = PMFW;
	if (PMFW == -1)
		SIZE = 0;
	ft_size(lst, SIZE);
}

// void		ft_check_size_g(t_type *lst, double n)
// {
// 	if (n < 0)
// 		n *= -1;
// 	SIZE = ft_strlen_num((uint64_t)n);
// 	PMFWG = PMFW;
// 	if (n < 1.0)
// 		ft_less_than_one(lst, n);
// 	else if ((SIZE <= 7 || PMFW >= SIZE || (PMFW > SIZE && PMFW >= 16)))
// 	{
// 		ft_check_size_f_g(lst, n);
// 		g_ok = 1;
// 	}
// 	else
// 		ft_check_size_f_e(lst, n);
// }

void		ft_check_size_g(t_type *lst, double n)
{
	SIZE = ft_strlen_num((uint64_t)n);
	if (n < 1.0)
	{
		if (FLAGS & 32 || (PMFW == 0 && PMFWG == 6))
		{
			PMFW = PMFWG;
			PMFWG = -1;
		}
		ft_less_than_one(lst, n);
	}
	else if ((SIZE <= 7 || PMFW >= SIZE || (PMFW > SIZE && PMFW >= 16)))
	{
		PMFWG = PMFW;
		ft_check_size_f_g(lst, n);
		g_ok = 1;
	}
	else
	{
		PMFWG = PMFW;
		ft_check_size_f_e(lst, n);
	}
}
