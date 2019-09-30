/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sub_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:53:41 by mathis            #+#    #+#             */
/*   Updated: 2019/09/30 13:06:19 by mbouanik         ###   ########.fr       */
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
			path = ft_strjoin(name, dp->d_name);
			lstat(path, &buf);
			if ((g_flags) & 2)
				ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
			else
			{
				if (dp->d_name[0] != '.')
					ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
			}
			if (((buf.st_mode & S_IFMT) == S_IFDIR))
			{
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name)
				&& (g_flags & 2))
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
			}
			bzero(&buf, sizeof(struct stat));
			free(path);
		}
	}
	if (!dp && dir)
		(void)closedir(dir);
	while (st_dir)
	{
		if (g_flags & 16)
			ft_printf("%s %d %s %s %6d %.15s %s\n", st_dir->mode,
			st_dir->n_link, st_dir->pw_name, st_dir->gr_name,
			st_dir->size, st_dir->date, st_dir->name);
		else
			ft_printf("%-10s ", st_dir->name);
		free_subdir(&st_dir);
	}
	if (!(g_flags & 16))
		ft_printf("\n");
	if (sub_dir && (g_flags & 1))
	{
		path = ft_strjoin(sub_dir->name, "/");
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, path, buf, sub_dir->next);
		free(path);
		free_subdir(&sub_dir);
	}
}
