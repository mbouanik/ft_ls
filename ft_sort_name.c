/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:59:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 20:03:49 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	ft_sort_name(char *s1, char *s2)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		++i;
	if (!s1[i] && s2[i])
	{
		if (g_flags & 4)
			return (1);
		else
			return (0);
	}
	if (s1[i] < s2[i])
	{
		if (g_flags & 4)
			return (1);
		else
			return (0);
	}
	else if (!s2[i] && s1[i])
	{
		if (g_flags & 4)
			return (0);
		else
			return (1);
	}
	else if (s2[i] < s1[i])
	{
		if (g_flags & 4)
			return (0);
		else
			return (1);
	}
	else
		return (-1);
}
