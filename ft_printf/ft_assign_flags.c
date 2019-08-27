/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:32:42 by mbouanik          #+#    #+#             */
/*   Updated: 2018/06/11 18:47:29 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag g_flag[] = {
	{'#', &ft_hash},
	{'-', &ft_minus},
	{'0', &ft_zero},
	{' ', &ft_blank},
	{'+', &ft_plus}
};

static void		ft_flags(char **f, t_type *lst)
{
	int i;

	if (**f == '#' || **f == '-' || **f == '0' || **f == ' ' || **f == '+')
		while (!(ft_isalpha(**f)) && !(ft_isdigit_s(**f)) && **f != '%'
			&& **f != '.' && **f != '*' && **f)
		{
			i = -1;
			while (++i <= 4)
				if (**f == g_flag[i].c)
					g_flag[i].f(lst);
			*f += 1;
		}
	if (FLAGS & 2 && FLAGS & 4)
		FLAGS &= 1011;
}

static void		ft_arg_type(t_type *lst, char **f)
{
	MOD |= *(*f)++;
	if ((**f == 'h' || **f == 'l'))
		MOD += *(*f)++;
	ft_flags(f, lst);
	if (ft_isalpha(**f))
		lst->arg_type = *(*f)++;
	if (ft_isalpha(**f))
		lst->arg_type = *(*f)++;
}

void			ft_assign_flags(char **f, t_type *lst, va_list list)
{
	ft_flags(f, lst);
	if (ft_isdigit_s(**f) || **f == '*' || **f == '.')
		while (!(ft_isalpha(**f)) && **f != '%' && **f)
		{
			if (ft_isdigit_s(**f) || **f == '*')
			{
				MFW = ft_atoi_s(f, list);
				if (MFW < 0)
				{
					FLAGS |= 2;
					MFW *= -1;
				}
			}
			else if (**f == '.' && (*f += 1))
			{
				PMFW = ft_atoi_s(f, list);
				if (PMFW == 0)
					PMFW = -1;
			}
			*f += 1;
		}
	if (**f == 'h' || **f == 'l' || **f == 'j' || **f == 'z')
		ft_arg_type(lst, f);
	else if (ft_isalpha(**f) || **f == '%')
		lst->arg_type = *(*f)++;
}
