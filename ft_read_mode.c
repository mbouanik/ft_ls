/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouanik <mbouanik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:28:46 by mbouanik          #+#    #+#             */
/*   Updated: 2019/09/27 19:12:42 by mbouanik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_usr_mode(struct stat *buf, char **mode)
{
	if (S_ISDIR(buf->st_mode))
		(*mode)[0] = 'd';
	else
		(*mode)[0] = '-';
	if (buf->st_mode & S_IRUSR)
		(*mode)[1] = 'r';
	else
		(*mode)[1] = '-';
	if (buf->st_mode & S_IWUSR)
		(*mode)[2] = 'w';
	else
		(*mode)[2] = '-';
	if (buf->st_mode & S_IXUSR)
		(*mode)[3] = 'x';
	else
		(*mode)[3] = '-';
}

void					ft_grp_mode(struct stat *buf, char *(*mode))
{
	if (buf->st_mode & S_IRGRP)
		(*mode)[4] = 'r';
	else
		(*mode)[4] = '-';
	if (buf->st_mode & S_IWGRP)
		(*mode)[5] = 'w';
	else
		(*mode)[5] = '-';
	if (buf->st_mode & S_IXGRP)
		(*mode)[6] = 'x';
	else
		(*mode)[6] = '-';
}

char					*ft_read_mode(struct stat *buf)
{
	char				*mode;

	mode = ft_memalloc(11);
	ft_usr_mode(buf, &mode);
	ft_grp_mode(buf, &mode);
	if (buf->st_mode & S_IROTH)
		mode[7] = 'r';
	else
		mode[7] = '-';
	if (buf->st_mode & S_IWOTH)
		mode[8] = 'w';
	else
		mode[8] = '-';
	if (buf->st_mode & S_IXOTH)
		mode[9] = 'x';
	else
		mode[9] = '-';
	return (mode);
}