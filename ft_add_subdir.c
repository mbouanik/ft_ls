/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:54:30 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/06 16:12:04 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_add_sub(t_dir_name **nsub_dir, t_dir_name *new_dir)
{
	t_dir_name *index;
	t_dir_name *tmp;

	tmp = NULL;
	index = NULL;
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

void			ft_add_subdir(t_dir_name **nsub_dir, char *str, struct stat buf)
{
	t_dir_name *new_dir;

	if (g_flags & 8)
	{
		ft_sub_time(nsub_dir, str, buf);
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
			ft_add_sub(nsub_dir, new_dir);
	}
}

void			ft_add_by_time(t_dir_name **nsub_dir, t_dir_name *new_dir)
{
	t_dir_name	*index;
	t_dir_name	*tmp;

	index = NULL;
	tmp = NULL;
	index = *nsub_dir;
	while ((*nsub_dir)->next != NULL)
	{
		if ((ft_sort_by_time((*nsub_dir)->next, new_dir)))
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

void			ft_sub_time(t_dir_name **nsub_dir, char *str, struct stat buf)
{
	t_dir_name	*index;
	t_dir_name	*new_dir;
	t_dir_name	*tmp;

	index = NULL;
	new_dir = NULL;
	tmp = NULL;
	new_dir = ft_new_subdir(str, buf);
	if (*nsub_dir == NULL)
		*nsub_dir = new_dir;
	else if (ft_sort_by_time(*nsub_dir, new_dir))
	{
		new_dir->next = (*nsub_dir);
		(*nsub_dir) = new_dir;
	}
	else
		ft_add_by_time(nsub_dir, new_dir);
}
