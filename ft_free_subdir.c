/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_subdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:56:16 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 20:14:14 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_subdir(t_dir_name **sub_dir)
{
	t_dir_name *temp;

	if ((*sub_dir)->next == NULL)
	{
		free((*sub_dir)->name);
		free((*sub_dir)->mode);
		free(*sub_dir);
		*sub_dir = NULL;
		return ;
	}

	temp = *sub_dir;
	*sub_dir = (*sub_dir)->next;
	free(temp->name);
	free(temp->mode);
	free((*sub_dir)->pw_name);
	free(temp);

	temp = NULL;
}

void		free_dir(t_dir_name **sub_dir)
{
	t_dir_name *temp;

	if ((*sub_dir)->next == NULL)
	{
		free((*sub_dir)->name);
		free((*sub_dir)->mode);
		free((*sub_dir)->pw_name);
		free(*sub_dir);
		*sub_dir = NULL;
		return ;
	}

	temp = *sub_dir;
	*sub_dir = (*sub_dir)->next;
	free(temp->name);
	free(temp->mode);
	free(temp);
	temp = NULL;
}
