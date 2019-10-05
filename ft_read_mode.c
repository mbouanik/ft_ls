/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:28:46 by mbouanik          #+#    #+#             */
/*   Updated: 2019/10/05 12:44:18 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_extended(struct stat buf, char **mode)
{
	acl_t acl = NULL;
    acl_entry_t dummy;
    ssize_t xattr = 0;

    acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
    if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
        acl_free(acl);
        acl = NULL;
    }
    xattr = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
    if (xattr < 0)
        xattr = 0;

    if (xattr > 0)
        (*mode)[10] = '@';
    else if (acl != NULL)
       (*mode)[10] = '+';
    else
    	(*mode)[10] = ' ';
	
}

void					ft_usr_mode(struct stat buf, char **mode)
{
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
		(*mode)[0] = 'l';
	else
	{
		if (S_ISDIR(buf.st_mode))
			(*mode)[0] = 'd';
		else
			(*mode)[0] = '-';
	}
	if (buf.st_mode & S_IRUSR)
		(*mode)[1] = 'r';
	else
		(*mode)[1] = '-';
	if (buf.st_mode & S_IWUSR)
		(*mode)[2] = 'w';
	else
		(*mode)[2] = '-';
	if (buf.st_mode & S_IXUSR)
		(*mode)[3] = 'x';
	else
		(*mode)[3] = '-';
}

void					ft_grp_mode(struct stat buf, char *(*mode))
{
	if (buf.st_mode & S_IRGRP)
		(*mode)[4] = 'r';
	else
		(*mode)[4] = '-';
	if (buf.st_mode & S_IWGRP)
		(*mode)[5] = 'w';
	else
		(*mode)[5] = '-';
	if (buf.st_mode & S_IXGRP)
		(*mode)[6] = 'x';
	else
		(*mode)[6] = '-';
}

char					*ft_read_mode(struct stat buf)
{
	char				*mode;

	mode = ft_memalloc(12);
	ft_usr_mode(buf, &mode);
	ft_grp_mode(buf, &mode);
	if (buf.st_mode & S_IROTH)
		mode[7] = 'r';
	else
		mode[7] = '-';
	if (buf.st_mode & S_IWOTH)
		mode[8] = 'w';
	else
		mode[8] = '-';
	if (buf.st_mode & S_IXOTH)
		mode[9] = 'x';
	else
		mode[9] = '-';
	return (mode);
}
