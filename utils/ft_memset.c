/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:44:04 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/25 21:42:40 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*str;

	str = NULL;
	i = 0;
	str = (char*)b;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (str);
}
