/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_subdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:55:20 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/29 13:24:01 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir_name		*ft_new_subdir(char *s, struct stat *buf)
{
	t_dir_name	*new_dir;

	new_dir = NULL;
	if ((new_dir = (t_dir_name *)malloc(sizeof(t_dir_name))))
	{
		new_dir->name = s;
		new_dir->next = NULL;
		new_dir->time = buf->st_mtime;
		new_dir->date = &ctime(&buf->st_mtimespec.tv_sec)[4];
		new_dir->size = buf->st_size;
		new_dir->n_link = buf->st_nlink;
		new_dir->pw_name = ft_strdup(getpwuid(buf->st_uid)->pw_name);
		new_dir->gr_name = ft_strdup(getgrgid(buf->st_gid)->gr_name);
		new_dir->mode = ft_read_mode(buf);
	}
	if (g_flags & 16)
	{
		if (ft_strlen(new_dir->pw_name) > g_pw_s)
			g_pw_s = ft_strlen(new_dir->pw_name) + 1;
		if (ft_strlen(new_dir->gr_name) > g_grp_s)
			g_grp_s = ft_strlen(new_dir->gr_name);
		if (ft_strlen_num(new_dir->size) > g_n_size)
			g_n_size = ft_strlen_num(new_dir->size);
		if (ft_strlen_num(new_dir->n_link) > g_nlink_s)
			g_nlink_s = ft_strlen_num(new_dir->n_link);
	}
	return (new_dir);
}
