/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sub_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:53:41 by mathis            #+#    #+#             */
/*   Updated: 2019/09/26 14:29:30 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	display_subdir(struct dirent * dp, char* name, struct stat *buf, t_dir_name  *sub_dir){

	t_dir_name *st_dir;
	st_dir = NULL;
	char * path;
	path = NULL;
			// ft_printf("PATH : %s\n",name);
		
	DIR * dir = NULL;
	dir = opendir(name);
	
	if (dir == NULL)
		ft_printf(" ls: %.*s: %s", ft_strlen(name) - 1, name, strerror(errno));

		// perror("ls");
	else {
	while ((dp = readdir(dir)) != NULL) {
		path = ft_strjoin(name, dp->d_name); 
		// ft_printf(" PAth: %s\n", path);
		lstat(path, buf);
		// if (dp->d_name[0] != '.')
			// ft_printf("sub: %s -- %X ",dp->d_name, buf->st_mode & S_IFMT);


        if((g_flags) & 2){
			ft_add_subdir(&st_dir, ft_strdup(dp->d_name));
		}
		else {
			if (dp->d_name[0] != '.')
				ft_add_subdir(&st_dir, ft_strdup(dp->d_name));

		}



		if (((buf->st_mode & S_IFMT) == S_IFDIR)){
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name) && (g_flags & 2))
					ft_add_subdir(&sub_dir, ft_strdup(path));
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path));
			  	// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			}





			// ft_add_subdir(&st_dir,   ft_strdup(dp->d_name));


			// if (((buf->st_mode & S_IFMT) == S_IFDIR)){
			// 	if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name) && (g_flags & 2))
			// 		ft_add_subdir(&sub_dir, ft_strdup(path));
			// 	else if (dp->d_name[0] != '.')
			// 		ft_add_subdir(&sub_dir, ft_strdup(path));
			//   	// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			// }
		
	free(path);
	// path = NULL;
	}
	}
	if (!dp && dir)
		(void)closedir(dir);
	while (st_dir)
	{
		ft_printf("%-10s ", st_dir->name);
		free_subdir(&st_dir);
		// st_dir = st_dir->next;
	}
	ft_printf("\n");
	if (sub_dir && (g_flags & 1)){
		path = ft_strjoin(sub_dir->name, "/");
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, path, buf, sub_dir->next);
		free(path);
		// ft_printf("Freed :  %s \n", sub_dir->name);
		// free(sub_dir->name);
		// free(sub_dir);
		// ft_free_struct(sub_dir);
		free_subdir(&sub_dir);
	}
}