/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/08/02 13:52:48 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include <dirent.h>
  #include <stdio.h>
  #include "ft_printf/ft_printf.h"
 #include <sys/stat.h>

void op_dir(struct dirent * dp){
  DIR * dir;
 struct dirent *ds;
  if (dp->d_type == 4 ){

      //  op_dir(dp);
     ft_printf("./%s:\n", dp->d_name);
    dir = opendir(dp->d_name);
    while ((ds = readdir(dir)) != NULL) {
          ft_printf("%s  type: %d\n",
           ds->d_name, ds->d_type, ds->d_reclen, ds->d_ino);
           
      }
  }
}

int ft_ls(void)
{
    DIR * dir;
    struct dirent *dp;
    dir = NULL;
	struct stat *restrict buf;
    dir = opendir(".");

    if(dir == NULL){
      perror("error");
      return 0;
    }
       while ((dp = readdir(dir)) != NULL) {
          ft_printf("%s ", dp->d_name);
		  stat(dp->d_name, buf);
		  ft_printf(" stat: %x\n", buf->st_mode);
         //  op_dir(dp);
      }
      closedir(dir);
    return 0;
}

int main(int argc, char const *argv[])
{
  ft_ls();
  return 0;
}
