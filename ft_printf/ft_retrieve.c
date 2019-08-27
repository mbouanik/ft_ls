/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 23:19:44 by mbouanik          #+#    #+#             */
/*   Updated: 2018/02/11 20:36:39 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_retrieve(va_list list)
{
	unsigned long int *retrieve;

	retrieve = va_arg(list, unsigned long int*);
	*retrieve = g_p + g_size;
}
