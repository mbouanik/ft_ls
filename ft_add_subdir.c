/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:54:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/29 14:40:28 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_add_sub_by_time(t_dir_name **nsub_dir, char *str, struct stat buf){

	t_dir_name	*index;
	t_dir_name	*new_dir;
	t_dir_name	*tmp;


	new_dir = ft_new_subdir(str, buf);
	if (*nsub_dir == NULL)
		*nsub_dir = new_dir;
	else if (ft_sort_by_time((*nsub_dir)->time, new_dir->time))
	{
		new_dir->next = (*nsub_dir);
		(*nsub_dir) = new_dir;
	}
	else
	{
		index = *nsub_dir;
		while ((*nsub_dir)->next != NULL)
		{
			if (ft_sort_by_time((*nsub_dir)->next->time, new_dir->time))
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
}

void			ft_add_subdir(t_dir_name** nsub_dir, char *str, struct stat buf){

	t_dir_name *index;
	t_dir_name *new_dir;
	t_dir_name *tmp;

	if (g_flags & 8)
	{
		ft_add_sub_by_time(nsub_dir, str, buf);
		return ;
	}
	else
	{
		new_dir = ft_new_subdir(str, buf);
		if (*nsub_dir == NULL)
			*nsub_dir = new_dir;
		else if (ft_sort_name((*nsub_dir)->name, new_dir->name))
		{
			new_dir->next = (*nsub_dir);
			(*nsub_dir) = new_dir;
		}
		else
		{
			index = *nsub_dir;
			while ((*nsub_dir)->next != NULL)
			{
				if (ft_sort_name((*nsub_dir)->next->name, new_dir->name))
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
	}
	// free(&str);
}
