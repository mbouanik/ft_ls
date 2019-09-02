/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/01 19:45:42 by mbouanik         ###   ########.fr       */
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


int 	ft_compare(char *s1, char *s2){
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		++i;
	// ft_printf("%c ---- %c\n", s1[i], s2[i]);
	if(!s1[i] && s2[i])
		return 0;
	if(s1[i] < s2[i])
		return 0;
	else if (!s2[i] && s1[i])
		return 1;
	else if (s2[i] < s1[i])
		return 1;
	else
		return -1;
}

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
	t_dir_name * new_dir;
	t_dir_name * tmp;


	new_dir = ft_new_subdir(str);
	if(*nsub_dir == NULL){
		*nsub_dir = new_dir;
	}
	else if (ft_compare((*nsub_dir)->name, new_dir->name)){
		new_dir->next = (*nsub_dir);
		 (*nsub_dir) = new_dir;
	}
	else {
		index = *nsub_dir;
		while((*nsub_dir)->next != NULL){
			 if (ft_compare((*nsub_dir)->next->name, new_dir->name)) {
				 tmp = (*nsub_dir)->next;
					(*nsub_dir)->next = new_dir;
					new_dir->next = tmp;
					tmp = NULL;
					break ;
			 }
				*nsub_dir = (*nsub_dir)->next;
			
			// else{
					
			// }
		}
		if ((*nsub_dir)->next == NULL)
				(*nsub_dir)->next = new_dir;
		*nsub_dir = index;
	}
}

void 	display_subdir(struct dirent * dp, char* name, struct stat *buf, t_dir_name  *sub_dir){

	t_dir_name *st_dir;
	st_dir = NULL;
	DIR * dir = opendir(name);
	if (dir == NULL)
		ft_printf("Access Denied \n");
	if (dir != NULL)
	while ((dp = readdir(dir)) != NULL) {
		stat(ft_strjoin(name, dp->d_name), buf);
		// if (dp->d_name[0] != '.')
			// ft_printf("sub: %s -- %X ",dp->d_name, buf->st_mode & S_IFMT);
		if (dp->d_name[0] != '.'){
				ft_add_subdir(&st_dir,  dp->d_name);
			if ((buf->st_mode & S_IFMT) == S_IFDIR)
				ft_add_subdir(&sub_dir, ft_strjoin(name, dp->d_name));
				// ft_printf("---%s ---", ft_strjoin(name, dp->d_name));
			
		}
	}
	while (st_dir)
	{
		ft_printf("%s  ", st_dir->name);
		st_dir = st_dir->next;
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
	t_dir_name *st_dir;
	char * path;

	sub_dir = NULL;
	st_dir = NULL;
	while ((dp = readdir(dir)) != NULL) {
		path = ft_strjoin(file_name, dp->d_name);
		stat(path, buf);
		if (dp->d_name[0] != '.'){
				ft_add_subdir(&st_dir, dp->d_name);
			if ((buf->st_mode & S_IFMT) == S_IFDIR)
				ft_add_subdir(&sub_dir, path);
		}
		path = NULL;
		free(path);
	}
	while (st_dir){
		ft_printf("%s  ", st_dir->name);
		st_dir = st_dir->next;
	}
	ft_printf("\n");
	free(file_name);
	if (sub_dir){
		ft_printf("\n%s:\n", ft_strjoin(sub_dir->name, "/"));
		display_subdir(dp, ft_strjoin(sub_dir->name, "/"), buf, sub_dir->next);
		free_subdir(&sub_dir);
	}
	// while (sub_dir){
	// 	ft_printf("\n%s:\n", ft_strjoin(sub_dir->name, "/"));
	// 	sub_dir = sub_dir->next;
	// }
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
	// free(root);

	
	// ft_printf("%d\n", ft_compare(".Angela", "AngelaA"));
	// ft_printf("%d\n", ft_compare(".AngelaB", ".AngelaA"));
	// ft_printf("%d\n", ft_compare(".Angela", "AngelaA"));
	// ft_printf("%d\n", ft_compare(".Angela", "AngelaA"));

	return 0;
}
