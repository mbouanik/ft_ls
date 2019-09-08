#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/ioctl.h>
#include "utils/utils.h"
 #include <dirent.h>
  #include <stdio.h>



typedef struct	s_dir_name 
{
	char *name;
	struct s_dir_name* next;
}				t_dir_name;






int ft_assign_ls_flags(char *s);
size_t			lenname(DIR * dir, struct dirent * dp);
int			ft_hidden_dir(char *s);
void ft_free_struct(t_dir_name *sub_dir);
int 	ft_sort_name(char *s1, char *s2);
void		free_subdir(t_dir_name ** sub_dir);
void		free_dir(t_dir_name ** sub_dir);
t_dir_name * 	 ft_new_subdir(char *s);
void			ft_add_subdir(t_dir_name** nsub_dir ,char * str);
int ft_ls(char * s);
void 	display_subdir(struct dirent * dp, char* name, struct stat *buf, t_dir_name  *sub_dir);
void 			ft_display_dir(struct dirent * dp, DIR * dir, struct stat * buf, char * file_name);

#endif