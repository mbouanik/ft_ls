/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:01:06 by mathis            #+#    #+#             */
/*   Updated: 2019/10/04 17:59:05 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_sort_args(t_dir_name **folders, char *s)
{
	struct stat		buf;

    lstat(s, &buf);
    ft_add_subdir(folders, s, buf);
}
