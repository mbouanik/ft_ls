/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:49:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 11:46:58 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat * buf, char * file_name){
	
	t_dir_name  *sub_dir;
	t_dir_name *st_dir;
	char * path;

	path = NULL;
	sub_dir = NULL;
	st_dir = NULL;
	// ft_printf("%s:", file_name);
	dir = opendir(file_name);
	if (dir == NULL){
		ft_printf("ft_ls: %.*s: %s", ft_strlen(file_name) - 1, file_name, strerror(errno));
	}
	else{
	while ((dp = readdir(dir)) != NULL) {
		// ft_printf("%s%s\n", file_name,dp->d_name);
		path = ft_strjoin(file_name, ft_strdup(dp->d_name));
		lstat(path, buf);
		// if (dp->d_name[0] != '.'){
		
		if((g_flags) & 2){
			ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
		}
		else {

			if (dp->d_name[0] != '.'){
				// ft_printf("%d -- %s \n",buf->st_size, listxattr(dp->d_name));
				ft_add_subdir(&st_dir, ft_strdup(dp->d_name), buf);
			}

		}



		if (((buf->st_mode & S_IFMT) == S_IFDIR)){
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name) && (g_flags & 2))
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path), buf);
			  	// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			}



		// if (dp->d_name[0] != '.'){
			// ft_printf("name %s\n", dp->d_name);
			// if (((buf->st_mode & S_IFMT) == S_IFDIR)){
			// 	if (dp->d_name[0] == '.')

			// 	ft_add_subdir(&sub_dir, ft_strdup(path));
			// }
		// }
		// }
		free(path);
		// path = NULL;
	}
	}
	// ft_printf("----%s ---\n", dp);
	
	
	while (st_dir){
		ft_printf("%-10s ", st_dir->name);
		free_dir(&st_dir);
		// st_dir = st_dir->next;
	}
	if (!dp && dir)
		(void)closedir(dir);
	ft_printf("\n");
	free(file_name);
	if (sub_dir && (g_flags & 1)){
		file_name = ft_strjoin(sub_dir->name, "/");
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, file_name , buf, sub_dir->next);
	free(file_name);

		// free(sub_dir->name);
		// free(sub_dir);
		free_subdir(&sub_dir);
		// ft_free_struct(sub_dir);
	}
	// while (sub_dir){
	// 	ft_printf("\n%s:\n", ft_strjoin(sub_dir->name, "/"));
	// 	sub_dir = sub_dir->next;
	// }
	
}
