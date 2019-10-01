/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:13:42 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/30 20:14:09 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_readlink(struct stat buf, char *path)
{
	char	*l;
	char	*res;
	int		r;

	r = 0;
	l = NULL;
	res = NULL;
	l = ft_strnew(buf.st_size);
	r = readlink(path, l, buf.st_size + 1);
	res = ft_strjoin(" -> ", l);
	free(l);
	if (r > 0)
		return (res);
	free(res);
	return (ft_strdup(""));
}
