/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sub_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:53:41 by mathis            #+#    #+#             */
/*   Updated: 2019/10/01 16:28:41 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_subdir(struct dirent *dp, char *name, struct stat buf, t_dir_name *sub_dir){

	t_dir_name	*st_dir;
	char		*path;
	DIR			*dir;

	dir = opendir(name);
	st_dir = NULL;
	path = NULL;
	bzero(&buf, sizeof(struct stat));
	if (dir == NULL)
		ft_printf(" ls: %.*s: %s", ft_strlen(name) - 1, name, strerror(errno));
	else
	{
		while ((dp = readdir(dir)) != NULL)
		{
			g_path = ft_strjoin(name, dp->d_name);
			lstat(g_path, &buf);
			ft_set(dp, buf, &st_dir, &sub_dir);
			bzero(&buf, sizeof(struct stat));
			free(g_path);
		}
	}
	if (!dp && dir)
		(void)closedir(dir);
	if ((g_flags & 16))
		ft_display_flag_l(&st_dir);
	else
		ft_display_ls(&st_dir);
	if (sub_dir)
	{
		path = ft_strjoin(sub_dir->name, "/");
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, path, buf, sub_dir->next);
		free(path);
		free_subdir(&sub_dir);
	}
}
