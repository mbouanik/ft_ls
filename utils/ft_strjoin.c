/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:55:21 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/25 21:45:03 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcat.c"
#include "ft_memalloc.c"
#include "ft_strlen.c"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
		if ((str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			ft_strcat(str, s1);
			ft_strcat(str, s2);
		}
	return (str);
}
