/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/27 20:02:21 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils/utils.h"
 #include <dirent.h>
  #include <stdio.h>
  #include "ft_printf/ft_printf.h"
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <pwd.h>
  #include <uuid/uuid.h>
  #include <sys/ioctl.h>


typedef struct	s_dir_name 
{
	char *name;
	struct s_dir_name* next;

}				t_dir_name;


void		free_subdir(t_dir_name ** sub_dir){
	t_dir_name * temp;

	temp = *sub_dir;
	*sub_dir = (*sub_dir)->next;
	temp->next = NULL;
	free(temp);
}

t_dir_name * 	 ft_new_subdir(char *s){
	t_dir_name * new_dir;

	new_dir = NULL;
	if((new_dir = (t_dir_name *)malloc(sizeof(t_dir_name)))){
		new_dir->name = s;
		new_dir->next = NULL;
	}
	return (new_dir);
}

void			ft_add_subdir(t_dir_name** nsub_dir ,char * str){
	
	t_dir_name *index;

	if(*nsub_dir == NULL){
		*nsub_dir = ft_new_subdir(str);
	}else {
		index = *nsub_dir;
		while((*nsub_dir)->next != NULL)
			*nsub_dir = (*nsub_dir)->next;
		(*nsub_dir)->next = ft_new_subdir(str);
		*nsub_dir = index;
	}
}

void 	display_subdir(struct dirent * dp, char* name, struct stat *buf, t_dir_name  *sub_dir){

	DIR * dir = opendir(name);
	if (dir == NULL)
		ft_printf("Access Denied \n");
	if (dir != NULL)
	while ((dp = readdir(dir)) != NULL) {
		stat(ft_strjoin(name, dp->d_name), buf);
		// if (dp->d_name[0] != '.')
			// ft_printf("sub: %s -- %X ",dp->d_name, buf->st_mode & S_IFMT);
		if (dp->d_name[0] != '.'){
			if ((buf->st_mode & S_IFMT) == S_IFDIR)
				ft_add_subdir(&sub_dir, ft_strjoin(name, dp->d_name));
				// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			ft_printf("%s  ", dp->d_name);
		}
	}
	ft_printf("\n");
	if (sub_dir){
		ft_printf("\n%s:\n", sub_dir->name);
		display_subdir(dp, ft_strjoin(sub_dir->name, "/"), buf, sub_dir->next);
		free_subdir(&sub_dir);
	}
}


void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat * buf, char * file_name){
	
	t_dir_name  *sub_dir;
	char * path;

	sub_dir = NULL;
	while ((dp = readdir(dir)) != NULL) {
		path = ft_strjoin(file_name, dp->d_name);
		stat(path, buf);
		if (dp->d_name[0] != '.'){
			if ((buf->st_mode & S_IFMT) == S_IFDIR)
				ft_add_subdir(&sub_dir, path);
			ft_printf("%s  ", dp->d_name);
		}
		path = NULL;
		free(path);
	}
	ft_printf("\n");
	free(file_name);
	if (sub_dir){
		ft_printf("\n%s:\n", ft_strjoin(sub_dir->name, "/"));
		display_subdir(dp, ft_strjoin(sub_dir->name, "/"), buf, sub_dir->next);
		free_subdir(&sub_dir);
	}
}

int ft_ls(char * s)
{
	DIR * dir;
	struct dirent *dp;
	struct stat buf;

	dir = NULL;
	dir = opendir(s);
	if(dir == NULL){
		perror("error");
	return (0);
	}
	ft_display_dir(dp, dir, &buf, s);
	closedir(dir);
	return 0;
}

int main(int ac, char  *av[])
{
	char * root;
	
	root = NULL;
	if (av[1] != NULL){
		if (ft_strlen(av[1]) > 1 && av[1][0] != '/' )
		 root = ft_strjoin(av[1], "/");
		 else
		 root = strdup(av[1]);
	}
	else{
		root = strdup("./");
	}
	ft_ls(root);
	// ft_printf("%.6f\n",12.34);
	// printf("%.6f\n",12.34);

	return 0;
}
