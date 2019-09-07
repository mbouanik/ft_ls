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




void ft_assign_ls_flags(char *s);
size_t			lenname(DIR * dir, struct dirent * dp);

#endif