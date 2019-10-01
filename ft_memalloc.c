/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:19:43 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 18:25:03 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	ptr = NULL;
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	return (ft_memset(ptr, 0, size));
}
