/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:49:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/29 14:44:27 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void			ft_display_dir(struct dirent *dp, DIR *dir, struct stat buf, char *file_name){

	t_dir_name	*sub_dir;
	t_dir_name	*st_dir;
	char		*path;
	char 		*dp_name;

	path = NULL;
	sub_dir = NULL;
	st_dir = NULL;
	// dp_name = NULL;
	dir = opendir(file_name);
		bzero(&buf, sizeof(struct stat));
	if (dir == NULL)
		ft_printf("ft_ls: %.*s: %s", ft_strlen(file_name) - 1,
		file_name, strerror(errno));
	else
		while ((dp = readdir(dir)) != NULL)
		{
			// dp_name = ft_strdup(dp->d_name);
			path = ft_strjoin(file_name, dp->d_name);
			lstat(path, &buf);
			if ((g_flags) & 2)
				ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
			else
			{
				if (dp->d_name[0] != '.')
					ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
			}
			if ((g_flags & 1) && ((buf.st_mode & S_IFMT) == S_IFDIR))
			{
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name)
				&& (g_flags & 2))
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
			}
			free(path);
			bzero(&buf, sizeof(struct stat));
			// free(dp_name);
		}
	while (st_dir)
	{
		if (g_flags & 16)
			ft_printf("%s %*d %-*s %-*s %*d %.12s %s\n",
			st_dir->mode, g_nlink_s, st_dir->n_link, g_pw_s, st_dir->pw_name,
			g_grp_s, st_dir->gr_name, g_n_size,
			st_dir->size, st_dir->date, st_dir->name);
		else
			ft_printf("%-10s ", st_dir->name);
		free_subdir(&st_dir);
	}
	if (!dp && dir)
		(void)closedir(dir);
	ft_printf("\n");
	free(file_name);
	if (sub_dir && (g_flags & 1))
	{
		file_name = ft_strjoin(sub_dir->name, "/");
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, file_name, buf, sub_dir->next);
		free_subdir(&sub_dir);
		free(file_name);
	}
}
