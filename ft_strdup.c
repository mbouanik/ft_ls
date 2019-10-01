/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:40:43 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 18:25:26 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if ((dest = ft_strnew(ft_strlen(s1))))
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	return (dest);
}
