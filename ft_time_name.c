/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:20:25 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/02 14:53:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_time_name_s(t_dir_name **nsub_dir, t_dir_name *new_dir)
{
	t_dir_name *index;
	t_dir_name *tmp;

	tmp = NULL;
	index = NULL;
	index = *nsub_dir;
	while ((*nsub_dir)->next != NULL&& 
	(*nsub_dir)->next->time == new_dir->time)
		*nsub_dir = (*nsub_dir)->next;
	
	while ((*nsub_dir)->next != NULL)
	{
		if (ft_sort_name((*nsub_dir)->next->name, new_dir->name) && 
	(*nsub_dir)->next->time == new_dir->time)
		{
			tmp = (*nsub_dir)->next;
			(*nsub_dir)->next = new_dir;
			new_dir->next = tmp;
			tmp = NULL;
			break ;
		}
		*nsub_dir = (*nsub_dir)->next;
	}
	if ((*nsub_dir)->next == NULL)
		(*nsub_dir)->next = new_dir;
	*nsub_dir = index;
	index = NULL;
}

void			ft_time_name(t_dir_name **nsub_dir, t_dir_name *new_dir)
{


	if (*nsub_dir == NULL)
		*nsub_dir = new_dir;
	else if (ft_sort_name((*nsub_dir)->name, new_dir->name) &&
	(*nsub_dir)->time == new_dir->time)
	{
		new_dir->next = (*nsub_dir);
		(*nsub_dir) = new_dir;
	}
	else
		ft_time_name_s(nsub_dir, new_dir);
}
