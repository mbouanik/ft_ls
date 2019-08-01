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
          ft_printf("%d \n", dp->d_type);
      }
      closedir(dir);
    return 0;
}

int main(int argc, char const *argv[])
{
  ft_ls();
  return 0;
}
