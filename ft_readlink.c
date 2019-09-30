/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:04:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 14:12:02 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_readlink(t_dir_name** nsub_dir, struct stat buf, char *path){
	(*nsub_dir)->linkname = malloc(buf.st_size + 1);
	(*nsub_dir)->linkname[buf.st_size + 1] ='\0';
	readlink(path, (*nsub_dir)->linkname, buf.st_size + 1);
	// ft_printf("%s\n", linkname);
}
