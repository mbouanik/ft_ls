/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:22:37 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/05 15:22:58 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_one_arg(char **av, t_dir_name **folders, int i)
{
	(av[i] == NULL) ? ft_ls(ft_strdup("./")) :
		ft_ls(ft_strjoin((*folders)->name, "/"));
	if ((*folders))
		free_subdir(folders);
}
