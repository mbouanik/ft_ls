/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:10:45 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/02 12:14:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sort_by_time(int time1, int time2)
{
	int r;

	r = 0;
	if (time1 > time2)
		r = 0;
	else if (time1 < time2)
		r = 1;
	else if (time1 == time2)
		return (-1);
	else
		r = 0;
	if (g_flags & 4)
		return (!r);
	return (r);
}
