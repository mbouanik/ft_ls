/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/06 18:46:06 by mbouanik         ###   ########.fr       */
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
	struct t_dir_name* next;
}				t_dir_name;


void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat *restrict buf){
	while ((dp = readdir(dir)) != NULL) {

		if (buf->st_mode ==  16877){

		}
		// ft_printf("%d ", w.ws_col); 
		//ft_printf("%-*s\n",lenname(dir, dp) + 1, dp->d_name);
		if (dp->d_name[0] != '.')
		ft_printf("%-10s ", dp->d_name);
	}
}


size_t			lenname(DIR * dir, struct dirent * dp){
	size_t size;
	size = 0;
	while ((dp = readdir(dir)) != NULL) {
		if (dp->d_namlen > size)
			size = dp->d_namlen ;
		}
	return size;
}

struct winsize w;

void			op_dir(struct dirent * dp, DIR * dir, struct stat *restrict buf){
	stat(dp->d_name, buf);
	ioctl(0, TIOCGWINSZ, &w);
	// if (buf->st_mode ==  16877){
	//ft_printf("\n./%s:\n", dp->d_name);
	//dir = opendir(dp->d_name);
	//op_dir(dp, dir, buf);
	//}
	ft_display_dir(dp, dir, buf);
	// ft_printf("\n");
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
	//while ((dp = readdir(dir)) != NULL) {
	//if (dp->d_name[0] != '.'){
	//ft_printf("%s \n", dp->d_name);
	//stat(dp->d_name, &buf);
	//ft_printf(" stat: %d\n", buf.st_mode);
	op_dir(dp, dir, &buf);
	//}
	//}
	closedir(dir);
	return 0;
}

int main(int argc, char const *argv[])
{
	ft_ls();
	return 0;
}
