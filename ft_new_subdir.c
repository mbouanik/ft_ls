/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:55:20 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/26 16:18:54 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_name * 	 ft_new_subdir(char *s, struct stat * buf){
	t_dir_name * new_dir;

	new_dir = NULL;
	if((new_dir = (t_dir_name *)malloc(sizeof(t_dir_name)))){
		new_dir->name = ft_strdup(s);
		new_dir->next = NULL;
		new_dir->time = buf->st_mtime;
	}
	free(s);
	return (new_dir);
}