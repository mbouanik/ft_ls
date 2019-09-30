/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:04:14 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 16:43:33 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_readlink(char **dir, struct stat buf, char *path)
{
	char *l;

	int r;
	r = 0;
	l = ft_strnew(buf.st_size);
	r = readlink(path, l, buf.st_size + 1);
		if (r > 0)
		*dir = ft_strjoin( " -> ", l);
	else
		*dir = ft_strdup("");
	free(l);
}
