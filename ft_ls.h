#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/xattr.h>
#include <grp.h>
#include <uuid/uuid.h>




typedef struct			s_dir_name 
{
	char 				*name;
	int 				time;
	char				*t;
	char				*date;
	char				*pw_name;
	char				*gr_name;
	int					size;
	int					n_link;
	char				*mode;
	char 				*linkname;
	struct s_dir_name	*next;
}						t_dir_name;

short 					g_flags;
int						g_pw_s;
int						g_grp_s;
int						g_n_size;
int						g_nlink_s;
char					*g_path;
int						g_block;

void 					ft_assign_ls_flags(char *s);
size_t					lenname(DIR * dir, struct dirent * dp);
int						ft_hidden_dir(char *s);
void 					ft_free_struct(t_dir_name *sub_dir);
int 					ft_sort_name(char *s1, char *s2);
void					free_subdir(t_dir_name ** sub_dir);
void					free_dir(t_dir_name ** sub_dir);
t_dir_name * 			ft_new_subdir(char *s, struct stat  buf);
void					ft_add_subdir(t_dir_name** nsub_dir ,char *str, struct stat buf);
int 					ft_ls(char * s);
void 					display_subdir(struct dirent * dp, char* name, struct stat buf, t_dir_name  *sub_dir);
void 					ft_display_dir(struct dirent * dp, DIR * dir, struct stat buf, char * file_name);
void					ft_add_sub_by_time(t_dir_name** nsub_dir, char * str, struct stat  buf);
int 					ft_sort_by_time(int time1, int time2);
char *					ft_read_mode(struct stat  buf);
char					*ft_readlink(struct stat buf, char *path);
void					*ft_memalloc(size_t size);
void					*ft_memset(void *b, int c, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strdup(const char *s1);
char					*ft_strnew(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s, unsigned int start, size_t len);

#endif