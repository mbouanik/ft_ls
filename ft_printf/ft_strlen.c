/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:38:20 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 18:33:03 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i])
			++i;
	return (i);
}

size_t	ft_strlen_uni(wchar_t *s)
{
	int i;

	i = 0;
	if (s != NULL)
		while (s[i])
			i++;
	return (i);
}

int		ft_size_uni(wchar_t *s, t_type *lst)
{
	int j;
	int size;
	int i;
	int	accu;

	size = 0;
	j = 0;
	i = 0;
	accu = 0;
	while (s[j] && j < SIZE)
	{
		i = ft_strlen_b(s[j]);
		if (MB_CUR_MAX == 1 && i > 0 && i <= 8)
			accu = -1;
		if (i >= 1 && i <= 7)
			size += 1;
		else if (i >= 8 && i <= 11)
			size += 2;
		else if (i >= 12 && i <= 16)
			size += 3;
		else if (i >= 17 && i <= 21)
			size += 4;
		j++;
	}
	return (size + accu);
}
