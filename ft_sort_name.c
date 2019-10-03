/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:59:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/01 19:35:46 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sort_name(char *s1, char *s2)
{
	int		i;
	int		r;

	i = 0;
	r = 0;

	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		++i;
	if (!s1[i] && s2[i])
		r = 0;
	else if (s1[i] < s2[i])
		r = 0;
	else if (!s2[i] && s1[i])
		r = 1;
	else if (s2[i] < s1[i])
		r = 1;
	if (g_flags & 4)
		return (!r);
	return (r);
}
