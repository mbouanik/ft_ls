/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 22:49:40 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/17 16:19:13 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg g_arg[] = {
	{'s', &ft_display_arg_s},
	{'S', &ft_display_arg_str_uni},
	{'c', &ft_display_arg_c},
	{'C', &ft_display_arg_c_uni},
	{'p', &ft_display_arg_p},
	{'b', &ft_display_arg_b},
	{'d', &ft_display_arg_d},
	{'i', &ft_display_arg_d},
	{'u', &ft_display_arg_u},
	{'D', &ft_display_arg_dd},
	{'x', &ft_display_arg_x},
	{'X', &ft_display_arg_xx},
	{'o', &ft_display_arg_o},
	{'O', &ft_display_arg_octal},
	{'U', &ft_display_arg_uu},
	{'f', &ft_display_arg_f},
	{'F', &ft_display_arg_f},
	{'e', &ft_display_arg_e},
	{'E', &ft_display_arg_e},
	{'g', &ft_display_arg_g},
	{'G', &ft_display_arg_g},
	{0, NULL}
};

void			ft_new(t_type *lst, int *j)
{
	lst->flags = 0;
	lst->mfw = 0;
	lst->pmfw = 0;
	lst->pmfwg = 0;
	lst->mod = 0;
	lst->size = 0;
	lst->arg_type = 0;
	*j = -1;
}

void			ft_init(void)
{
	g_size = 0;
	g_p = 0;
	g_keep = 1;
	g_ok = 0;
}

void			ft_arg(t_type *lst, int c, va_list list)
{
	if (lst->arg_type == 'n')
		ft_retrieve(list);
	else if (c == 0)
		ft_display_no_arg(lst);
}

int				ft_printf(char *format, ...)
{
	va_list		list;
	t_type		lst;
	int			j;

	va_start(list, format);
	ft_init();
	while (*format && g_keep)
	{
		ft_new(&lst, &j);
		ft_cp_until(g_str, &format, '%');
		if (*format == '%' && (format++) && *format)
		{
			ft_assign_flags(&format, &lst, list);
			while (lst.arg_type != g_arg[j].c && g_arg[++j].c)
				if (lst.arg_type == g_arg[j].c)
					g_arg[j].f(&lst, list);
		}
		g_ok = g_p;
		ft_arg(&lst, g_arg[j].c, list);
	}
	ft_putstr_g(g_str);
	va_end(list);
	if (g_keep)
		g_size += g_p;
	return (g_size);
}
