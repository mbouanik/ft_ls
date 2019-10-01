/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:22:49 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 18:33:28 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_s(char **str, va_list list)
{
	int		nb;

	nb = 0;
	if (**str == '*')
		return (va_arg(list, int));
	while (**str >= '0' && **str <= '9')
	{
		nb = (nb * 10) + (**str - 48);
		*str += 1;
	}
	*str -= 1;
	return (nb);
}
