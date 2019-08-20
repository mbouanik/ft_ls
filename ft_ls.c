/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/20 01:07:11 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void			op_dir(struct dirent * dp, DIR * dir, struct stat *restrict buf);
void			ft_add_subdir(t_dir_name** nsub_dir ,char * str);
size_t			lenname(DIR * dir, struct dirent * dp);
void		free_subdir(t_dir_name ** sub_dir);
void 	display_subdir(struct dirent * dp, DIR * dir, struct stat *restrict buf, t_dir_name  *sub_dir);



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

void 	display_subdir(struct dirent * dp, DIR * dir, struct stat *restrict buf, t_dir_name  *sub_dir){
	while ((dp = readdir(dir)) != NULL) {
		stat(dp->d_name, buf);
		if (dp->d_name[0] != '.')
			ft_printf("sub: %s -- %X\n",dp->d_name,buf->st_mode & S_IFDIR);
		if (dp->d_name[0] != '.'){
			if (buf->st_mode & S_IFDIR)//S_IFDIR)
				ft_add_subdir(&sub_dir, dp->d_name);
			ft_printf("%-s\n", dp->d_name);
		}
	}
	ft_printf("\n");
	if (sub_dir){
		stat(sub_dir->name, buf);
		// 	while (sub_dir){
		ft_printf("Love: %s, type: %x\n",sub_dir->name, buf->st_mode);
		ft_printf("\n./%s\n", sub_dir->name);
			if (buf->st_mode & S_IFDIR)
				display_subdir(dp, opendir(sub_dir->name), buf, sub_dir->next);

		free_subdir(&sub_dir);
	// 	// sub_dir = sub_dir->next;
	// 	free_subdir(&sub_dir);
	// closedir(dir);
	}

}


void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat *restrict buf){
	
	t_dir_name  *sub_dir;
	
	sub_dir = NULL;
	while ((dp = readdir(dir)) != NULL) {
		stat(dp->d_name, buf);
		if (dp->d_name[0] != '.')
			ft_printf("\nsub: %s -- %X ",dp->d_name,buf->st_mode);

		if (dp->d_name[0] != '.'){
			if (buf->st_mode & S_IFDIR)
				ft_add_subdir(&sub_dir, dp->d_name);
			ft_printf("%-s\n", dp->d_name);
		}
	}
	// ft_printf("\n");
	while (sub_dir){
		// ft_printf("%s\n", sub_dir->name);
		ft_printf("\n./%s:\n", sub_dir->name);
		display_subdir(dp, opendir(sub_dir->name), buf, sub_dir);
		// sub_dir = sub_dir->next;
		free_subdir(&sub_dir);

	}
		if (sub_dir)
			ft_printf("BLoooeo");
	// }

	// if (sub_dir->next)
	// 	sub_dir = sub_dir->next;
	// 	while (sub_dir != NULL){
		
	// 	dir = opendir(sub_dir->name);
		
	// 	sub_dir = sub_dir->next;
	// 	ft_display_dir(dp,dir, buf);
	// }
		
	
	// if (sub_dir != NULL){
	// 		ft_printf("subdir :%s  --  %p\n", sub_dir->name, sub_dir->next);
	// 		sub_dir = sub_dir->next;
	// 	}
}


size_t			lenname(DIR * dir, struct dirent * dp){
	
	size_t size;
	struct dirent * index;

	index = dp;

	size = 0;
	while ((dp = readdir(dir)) != NULL) {
		if (dp->d_namlen > size)
			size = dp->d_namlen ;
		}
	dp = index;
	return size;
}

struct winsize w;

void			op_dir(struct dirent * dp, DIR * dir, struct stat *restrict buf){
	
	stat(dp->d_name, buf);
	// ioctl(0, TIOCGWINSZ, &w);
	ft_display_dir(dp, dir, buf);
}

int ft_ls(void)
{
	DIR * dir;
	struct dirent *dp;
	dir = NULL;
	struct stat  buf;
	dir = opendir(".");

	if(dir == NULL){
		perror("error");
	return (0);
	}
	op_dir(dp, dir, &buf);
	closedir(dir);
	return 0;
}

int main(int argc, char const *argv[])
{
	ft_ls();
	return 0;
}
