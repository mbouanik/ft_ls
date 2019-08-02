/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:57:36 by mbouanik          #+#    #+#             */
/*   Updated: 2019/07/31 16:55:09 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  #include <dirent.h>
  #include <stdio.h>
  #include "ft_printf/ft_printf.h"

void op_dir(struct dirent * dp){
  DIR * dir;
 struct dirent * ds;
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
    struct dirent * dp;
    dir = NULL;
    dir = opendir(".");

    if(dir == NULL){
      perror("error");
      return 0;
    }
       while ((dp = readdir(dir)) != NULL) {
          ft_printf("%s\n",
           dp->d_name, dp->d_type, dp->d_reclen, dp->d_ino);
           op_dir(dp);
      }
      closedir(dir);
    return 0;
}

int main(int argc, char const *argv[])
{
  ft_ls();
  return 0;
}
