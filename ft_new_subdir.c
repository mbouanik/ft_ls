/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:55:20 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 20:00:49 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_name		*ft_new_subdir(char *s, struct stat *buf)
{
	t_dir_name	*new_dir;

	new_dir = NULL;
	if ((new_dir = (t_dir_name *)malloc(sizeof(t_dir_name))))
	{
		new_dir->name = ft_strdup(s);
		new_dir->next = NULL;
		new_dir->time = buf->st_mtime;
		new_dir->date = &ctime(&buf->st_mtimespec.tv_sec)[4];
		new_dir->size = buf->st_size;
		new_dir->n_link = buf->st_nlink;
		new_dir->pw_name = getpwuid(buf->st_uid)->pw_name;
		new_dir->gr_name = getgrgid(buf->st_gid)->gr_name;
		new_dir->mode = ft_read_mode(buf);
	}
	free(s);
	return (new_dir);
}
