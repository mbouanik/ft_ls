/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_by_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:10:45 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/08 11:26:20 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sort_by_time(t_dir_name *nsub_dir, t_dir_name *new_dir)
{
	int r;

	r = 0;
	if (nsub_dir->time > new_dir->time)
		r = 0;
	else if (nsub_dir->time < new_dir->time)
		r = 1;
	else if (nsub_dir->time == new_dir->time)
	{
		if (nsub_dir->ntime > new_dir->ntime)
			r = 0;
		else if (nsub_dir->ntime < new_dir->ntime)
			r = 1;
	}
	if (g_flags & 4)
		return (!r);
	return (r);
}
