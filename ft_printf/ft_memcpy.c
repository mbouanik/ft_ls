/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:38:13 by mbouanik          #+#    #+#             */
/*   Updated: 2016/11/18 21:07:17 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*sc;
	char	*des;
	size_t	i;

	sc = (char*)src;
	des = (char*)dest;
	i = 0;
	while (i < n)
	{
		des[i] = sc[i];
		i++;
	}
	return (des);
}
