/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:49:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/07 18:25:17 by mbouanik         ###   ########.fr       */
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
		perror("ls");
	else {
	while ((dp = readdir(dir)) != NULL) {
		path = ft_strjoin(name, dp->d_name); 
		// ft_printf(" PAth: %s\n", path);
		lstat(path, buf);
		// if (dp->d_name[0] != '.')
			// ft_printf("sub: %s -- %X ",dp->d_name, buf->st_mode & S_IFMT);
			ft_add_subdir(&st_dir,   ft_strdup(dp->d_name));


			if (((buf->st_mode & S_IFMT) == S_IFDIR)){
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name) && (g_flags &2))
					ft_add_subdir(&sub_dir, ft_strdup(path));
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path));
			  	// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			}
		
	free(path);
	// path = NULL;
	}
	}
	if (!dp && dir)
		(void)closedir(dir);
	while (st_dir)
	{
		ft_printf("%s ", st_dir->name);
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


void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat * buf, char * file_name){
	
	t_dir_name  *sub_dir;
	t_dir_name *st_dir;
	char * path;

	path = NULL;
	sub_dir = NULL;
	st_dir = NULL;

	dir = opendir(file_name);
	if (dir == NULL)
		perror("error");

	else{
	while ((dp = readdir(dir)) != NULL) {
		// ft_printf("%s%s\n", file_name,dp->d_name);
		path = ft_strjoin(file_name, ft_strdup(dp->d_name));
		lstat(path, buf);
		// if (dp->d_name[0] != '.'){
				ft_add_subdir(&st_dir, ft_strdup(dp->d_name));




		if (((buf->st_mode & S_IFMT) == S_IFDIR)){
				if (dp->d_name[0] == '.' && ft_hidden_dir(dp->d_name) && (g_flags & 2))
					ft_add_subdir(&sub_dir, ft_strdup(path));
				else if (dp->d_name[0] != '.')
					ft_add_subdir(&sub_dir, ft_strdup(path));
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
		ft_printf("%s ", st_dir->name);
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
